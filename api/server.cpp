// ─────────────────────────────────────────────────────────────────────────────
//  Tarot Card Reader — Crow REST API
//  Endpoints:
//    GET  /health             → liveness check for Render
//    GET  /api/cards          → list all 10 cards
//    GET  /api/moods          → list all 5 moods
//    POST /api/reading        → perform a reading
//    GET  /api/history        → full session history (in-memory)
// ─────────────────────────────────────────────────────────────────────────────

#include "crow_all.h"

// Pull in all tarot logic (paths relative to project root)
#include "../models/User.h"
#include "../models/TarotCard.h"
#include "../models/Card.h"
#include "../services/TarotDeck.h"
#include "../services/TarotEngine.h"
#include "../utils/TarotCombinations.h"

#include <string>
#include <vector>
#include <mutex>

// ── Global state (one engine per process, mutex-protected) ────────────────────
static TarotEngine  g_engine;
static std::mutex   g_mutex;

// ── Helpers ───────────────────────────────────────────────────────────────────

// Card index (1-10) -> display name
static const char* CARD_NAMES[11] = {
    "", "The Fool", "The Magician", "The High Priestess",
    "The Empress", "The Emperor", "The Lovers",
    "The Chariot", "Strength", "The Hermit", "The Star"
};

// Mood string -> User::Mood enum
static User::Mood parseMood(const std::string& s) {
    if (s == "Happy"   || s == "happy")   return User::Mood::Happy;
    if (s == "Sad"     || s == "sad")     return User::Mood::Sad;
    if (s == "Neutral" || s == "neutral") return User::Mood::Neutral;
    if (s == "Confused"|| s == "confused")return User::Mood::Confused;
    if (s == "Excited" || s == "excited") return User::Mood::Excited;
    return User::Mood::Neutral;
}

// Validate card index
static bool validCard(int i) { return i >= 1 && i <= 10; }

// Add CORS headers to every response
static void addCors(crow::response& res) {
    res.add_header("Access-Control-Allow-Origin",  "*");
    res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
    res.add_header("Access-Control-Allow-Headers", "Content-Type");
}

// ── main ──────────────────────────────────────────────────────────────────────
int main() {
    crow::SimpleApp app;

    // ── OPTIONS preflight (CORS) ─────────────────────────────────────────────
    CROW_ROUTE(app, "/api/<path>").methods(crow::HTTPMethod::OPTIONS)
    ([](const crow::request&, crow::response& res, std::string) {
        addCors(res);
        res.code = 204;
        res.end();
    });

    // ── GET /health ──────────────────────────────────────────────────────────
    CROW_ROUTE(app, "/health")
    ([](crow::response& res) {
        addCors(res);
        res.set_header("Content-Type", "application/json");
        res.write(R"({"status":"ok","service":"Tarot Card Reader API"})");
        res.end();
    });

    // ── GET /api/cards ───────────────────────────────────────────────────────
    CROW_ROUTE(app, "/api/cards")
    ([](crow::response& res) {
        addCors(res);
        res.set_header("Content-Type", "application/json");

        crow::json::wvalue data;
        for (int i = 1; i <= 10; ++i) {
            data["cards"][i-1]["id"]   = i;
            data["cards"][i-1]["name"] = CARD_NAMES[i];
        }
        res.write(data.dump());
        res.end();
    });

    // ── GET /api/moods ───────────────────────────────────────────────────────
    CROW_ROUTE(app, "/api/moods")
    ([](crow::response& res) {
        addCors(res);
        res.set_header("Content-Type", "application/json");

        crow::json::wvalue data;
        std::vector<std::string> moods = {"Happy","Sad","Neutral","Confused","Excited"};
        for (int i = 0; i < (int)moods.size(); ++i) {
            data["moods"][i]["id"]   = i + 1;
            data["moods"][i]["name"] = moods[i];
        }
        res.write(data.dump());
        res.end();
    });

    // ── POST /api/reading ────────────────────────────────────────────────────
    //  Request JSON:
    //  {
    //    "name":    "Suhani",
    //    "mood":    "Happy",          // or 1-5
    //    "past":    1,                // card index 1-10
    //    "present": 3,
    //    "future":  7
    //  }
    //
    //  Response JSON:
    //  {
    //    "name":    "Suhani",
    //    "mood":    "Happy",
    //    "cards": {
    //      "past":    { "id": 1, "name": "The Fool"    },
    //      "present": { "id": 3, "name": "The High Priestess" },
    //      "future":  { "id": 7, "name": "The Chariot" }
    //    },
    //    "reading": {
    //      "past":       "...",
    //      "present":    "...",
    //      "future":     "...",
    //      "synergy":    "...",
    //      "suggestion": "..."
    //    }
    //  }
    CROW_ROUTE(app, "/api/reading").methods(crow::HTTPMethod::POST)
    ([](const crow::request& req, crow::response& res) {
        addCors(res);
        res.set_header("Content-Type", "application/json");

        // ── Parse body ───────────────────────────────────────────────────────
        auto body = crow::json::load(req.body);
        if (!body) {
            res.code = 400;
            res.write(R"({"error":"Invalid JSON body"})");
            res.end();
            return;
        }

        // name
        std::string name = "Seeker";
        if (body.has("name") && body["name"].t() == crow::json::type::String)
            name = body["name"].s();

        // mood — accept string or int
        User::Mood mood = User::Mood::Neutral;
        if (body.has("mood")) {
            auto& m = body["mood"];
            if (m.t() == crow::json::type::String)
                mood = parseMood(std::string(m.s()));
            else if (m.t() == crow::json::type::Number)
                mood = static_cast<User::Mood>((int)m.i());
        }

        // card indices
        if (!body.has("past") || !body.has("present") || !body.has("future")) {
            res.code = 400;
            res.write(R"({"error":"Missing fields: past, present, future (card indices 1-10)"})");
            res.end();
            return;
        }

        int pastIdx    = (int)body["past"].i();
        int presentIdx = (int)body["present"].i();
        int futureIdx  = (int)body["future"].i();

        // Validate
        if (!validCard(pastIdx) || !validCard(presentIdx) || !validCard(futureIdx)) {
            res.code = 400;
            res.write(R"({"error":"Card indices must be between 1 and 10"})");
            res.end();
            return;
        }
        if (pastIdx == presentIdx || pastIdx == futureIdx || presentIdx == futureIdx) {
            res.code = 400;
            res.write(R"({"error":"Each card must be unique — no duplicates allowed"})");
            res.end();
            return;
        }

        // ── Perform reading (thread-safe) ────────────────────────────────────
        User user;
        user.setName(name);
        user.setMood(mood);

        std::string past_text, present_text, future_text, synergy_text, suggestion_text;
        {
            std::lock_guard<std::mutex> lock(g_mutex);
            past_text       = g_engine.getPastMeaning(pastIdx, presentIdx, futureIdx);
            present_text    = g_engine.getPresentMeaning(pastIdx, presentIdx, futureIdx);
            future_text     = g_engine.getFutureMeaning(pastIdx, presentIdx, futureIdx);
            synergy_text    = g_engine.getSynergy(pastIdx, presentIdx, futureIdx);
            suggestion_text = g_engine.getSuggestion(pastIdx, presentIdx, futureIdx);
        }

        // Apply mood tone to synergy
        synergy_text = applyMoodTone(synergy_text, mood);

        // ── Build response ───────────────────────────────────────────────────
        crow::json::wvalue resp;
        resp["name"] = name;
        resp["mood"] = user.getMoodString();

        resp["cards"]["past"]["id"]      = pastIdx;
        resp["cards"]["past"]["name"]    = CARD_NAMES[pastIdx];
        resp["cards"]["present"]["id"]   = presentIdx;
        resp["cards"]["present"]["name"] = CARD_NAMES[presentIdx];
        resp["cards"]["future"]["id"]    = futureIdx;
        resp["cards"]["future"]["name"]  = CARD_NAMES[futureIdx];

        resp["reading"]["past"]       = past_text;
        resp["reading"]["present"]    = present_text;
        resp["reading"]["future"]     = future_text;
        resp["reading"]["synergy"]    = synergy_text;
        resp["reading"]["suggestion"] = suggestion_text;

        res.write(resp.dump());
        res.end();
    });

    // ── GET /api/history ─────────────────────────────────────────────────────
    CROW_ROUTE(app, "/api/history")
    ([](crow::response& res) {
        addCors(res);
        res.set_header("Content-Type", "application/json");

        // History is in TarotEngine — expose reading count for now
        // Full history would need a getter added to TarotEngine
        std::lock_guard<std::mutex> lock(g_mutex);
        crow::json::wvalue data;
        data["readings_this_session"] = g_engine.readingCount();
        data["note"] = "Full history persisted in data/history.txt on the server";
        res.write(data.dump());
        res.end();
    });

    // ── Start server ─────────────────────────────────────────────────────────
    // Render injects PORT env variable — default to 8080 for local dev
    const char* port_env = std::getenv("PORT");
    uint16_t port = port_env ? (uint16_t)std::stoi(port_env) : 8080;

    std::cout << "Tarot API starting on port " << port << std::endl;
    app.port(port).multithreaded().run();

    return 0;
}
