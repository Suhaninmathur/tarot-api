// ─────────────────────────────────────────────────────────────────────────────
//  Tarot Card Reader — Minimal HTTP REST API
//  Uses only POSIX sockets + C++ stdlib — zero external dependencies
// ─────────────────────────────────────────────────────────────────────────────

#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <mutex>
#include <cstring>
#include <cstdlib>

// POSIX socket headers
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Tarot engine
#include "../models/User.h"
#include "../models/TarotCard.h"
#include "../models/Card.h"
#include "../services/TarotDeck.h"
#include "../services/TarotEngine.h"
#include "../utils/TarotCombinations.h"

// ── Global state ──────────────────────────────────────────────────────────────
static TarotEngine g_engine;
static std::mutex  g_mutex;

static const char* CARD_NAMES[11] = {
    "", "The Fool", "The Magician", "The High Priestess",
    "The Empress", "The Emperor", "The Lovers",
    "The Chariot", "Strength", "The Hermit", "The Star"
};

// ── JSON helpers ──────────────────────────────────────────────────────────────
static std::string jsonStr(const std::string& s) {
    std::string out = "\"";
    for (char c : s) {
        if (c == '"')  out += "\\\"";
        else if (c == '\\') out += "\\\\";
        else if (c == '\n') out += "\\n";
        else if (c == '\r') out += "\\r";
        else out += c;
    }
    return out + "\"";
}

// ── Simple JSON parser — extract string/int values ────────────────────────────
static std::string parseJsonString(const std::string& json, const std::string& key) {
    std::string search = "\"" + key + "\"";
    size_t pos = json.find(search);
    if (pos == std::string::npos) return "";
    pos = json.find(':', pos);
    if (pos == std::string::npos) return "";
    pos = json.find('"', pos);
    if (pos == std::string::npos) return "";
    size_t end = json.find('"', pos + 1);
    if (end == std::string::npos) return "";
    return json.substr(pos + 1, end - pos - 1);
}

static int parseJsonInt(const std::string& json, const std::string& key) {
    std::string search = "\"" + key + "\"";
    size_t pos = json.find(search);
    if (pos == std::string::npos) return -1;
    pos = json.find(':', pos);
    if (pos == std::string::npos) return -1;
    pos++;
    while (pos < json.size() && (json[pos] == ' ' || json[pos] == '\t')) pos++;
    return std::atoi(json.c_str() + pos);
}

// ── Mood parser ───────────────────────────────────────────────────────────────
static User::Mood parseMood(const std::string& s) {
    if (s == "Happy"   || s == "happy")    return User::Mood::Happy;
    if (s == "Sad"     || s == "sad")      return User::Mood::Sad;
    if (s == "Neutral" || s == "neutral")  return User::Mood::Neutral;
    if (s == "Confused"|| s == "confused") return User::Mood::Confused;
    if (s == "Excited" || s == "excited")  return User::Mood::Excited;
    return User::Mood::Neutral;
}

// ── HTTP response builder ─────────────────────────────────────────────────────
static std::string httpResponse(int code, const std::string& body) {
    std::string status = (code == 200) ? "200 OK" :
                         (code == 400) ? "400 Bad Request" : "500 Internal Server Error";
    std::ostringstream res;
    res << "HTTP/1.1 " << status << "\r\n"
        << "Content-Type: application/json\r\n"
        << "Access-Control-Allow-Origin: *\r\n"
        << "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
        << "Access-Control-Allow-Headers: Content-Type\r\n"
        << "Content-Length: " << body.size() << "\r\n"
        << "Connection: close\r\n"
        << "\r\n"
        << body;
    return res.str();
}

// ── Route handlers ────────────────────────────────────────────────────────────
static std::string handleHealth() {
    return R"({"status":"ok","service":"Tarot Card Reader API"})";
}

static std::string handleCards() {
    std::ostringstream j;
    j << "{\"cards\":[";
    for (int i = 1; i <= 10; ++i) {
        if (i > 1) j << ",";
        j << "{\"id\":" << i << ",\"name\":" << jsonStr(CARD_NAMES[i]) << "}";
    }
    j << "]}";
    return j.str();
}

static std::string handleMoods() {
    return R"({"moods":[
        {"id":1,"name":"Happy"},
        {"id":2,"name":"Sad"},
        {"id":3,"name":"Neutral"},
        {"id":4,"name":"Confused"},
        {"id":5,"name":"Excited"}
    ]})";
}

static std::string handleReading(const std::string& body) {
    std::string name = parseJsonString(body, "name");
    if (name.empty()) name = "Seeker";

    std::string moodStr = parseJsonString(body, "mood");
    User::Mood mood = parseMood(moodStr);

    int pastIdx    = parseJsonInt(body, "past");
    int presentIdx = parseJsonInt(body, "present");
    int futureIdx  = parseJsonInt(body, "future");

    // Validate
    if (pastIdx < 1 || pastIdx > 10 || presentIdx < 1 || presentIdx > 10 || futureIdx < 1 || futureIdx > 10)
        return "";  // signal 400
    if (pastIdx == presentIdx || pastIdx == futureIdx || presentIdx == futureIdx)
        return "";

    User user;
    user.setName(name);
    user.setMood(mood);

    std::string past_t, present_t, future_t, synergy_t, suggestion_t;
    {
        std::lock_guard<std::mutex> lock(g_mutex);
        past_t       = g_engine.getPastMeaning(pastIdx, presentIdx, futureIdx);
        present_t    = g_engine.getPresentMeaning(pastIdx, presentIdx, futureIdx);
        future_t     = g_engine.getFutureMeaning(pastIdx, presentIdx, futureIdx);
        synergy_t    = g_engine.getSynergy(pastIdx, presentIdx, futureIdx);
        suggestion_t = g_engine.getSuggestion(pastIdx, presentIdx, futureIdx);
    }

    synergy_t = applyMoodTone(synergy_t, mood);

    std::ostringstream j;
    j << "{"
      << "\"name\":"    << jsonStr(name) << ","
      << "\"mood\":"    << jsonStr(user.getMoodString()) << ","
      << "\"cards\":{"
      <<   "\"past\":"    << "{\"id\":" << pastIdx    << ",\"name\":" << jsonStr(CARD_NAMES[pastIdx])    << "},"
      <<   "\"present\":" << "{\"id\":" << presentIdx << ",\"name\":" << jsonStr(CARD_NAMES[presentIdx]) << "},"
      <<   "\"future\":"  << "{\"id\":" << futureIdx  << ",\"name\":" << jsonStr(CARD_NAMES[futureIdx])  << "}"
      << "},"
      << "\"reading\":{"
      <<   "\"past\":"       << jsonStr(past_t)       << ","
      <<   "\"present\":"    << jsonStr(present_t)    << ","
      <<   "\"future\":"     << jsonStr(future_t)     << ","
      <<   "\"synergy\":"    << jsonStr(synergy_t)    << ","
      <<   "\"suggestion\":" << jsonStr(suggestion_t)
      << "}"
      << "}";
    return j.str();
}

// ── Request dispatcher ────────────────────────────────────────────────────────
static void handleClient(int clientSock) {
    char buf[8192] = {};
    int bytes = recv(clientSock, buf, sizeof(buf) - 1, 0);
    if (bytes <= 0) { close(clientSock); return; }

    std::string req(buf, bytes);

    // Parse method and path
    std::istringstream reqStream(req);
    std::string method, path, version;
    reqStream >> method >> path >> version;

    // Strip query string
    size_t qpos = path.find('?');
    if (qpos != std::string::npos) path = path.substr(0, qpos);

    // Extract body (after \r\n\r\n)
    std::string body;
    size_t bodyPos = req.find("\r\n\r\n");
    if (bodyPos != std::string::npos) body = req.substr(bodyPos + 4);

    std::string respBody;
    int code = 200;

    if (method == "OPTIONS") {
        respBody = "{}";
    } else if (path == "/health") {
        respBody = handleHealth();
    } else if (path == "/api/cards" && method == "GET") {
        respBody = handleCards();
    } else if (path == "/api/moods" && method == "GET") {
        respBody = handleMoods();
    } else if (path == "/api/reading" && method == "POST") {
        respBody = handleReading(body);
        if (respBody.empty()) {
            code = 400;
            respBody = R"({"error":"Invalid card indices (1-10, no duplicates) or missing fields"})";
        }
    } else {
        code = 400;
        respBody = R"({"error":"Route not found"})";
    }

    std::string response = httpResponse(code, respBody);
    send(clientSock, response.c_str(), response.size(), 0);
    close(clientSock);
}

// ── main ──────────────────────────────────────────────────────────────────────
int main() {
    const char* port_env = std::getenv("PORT");
    int port = port_env ? std::atoi(port_env) : 8080;

    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock < 0) { std::cerr << "socket() failed\n"; return 1; }

    int opt = 1;
    setsockopt(serverSock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    sockaddr_in addr{};
    addr.sin_family      = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port        = htons(port);

    if (bind(serverSock, (sockaddr*)&addr, sizeof(addr)) < 0) {
        std::cerr << "bind() failed\n"; return 1;
    }
    listen(serverSock, 128);

    std::cout << "Tarot API running on port " << port << std::endl;

    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);
        int clientSock = accept(serverSock, (sockaddr*)&clientAddr, &clientLen);
        if (clientSock < 0) continue;
        // Handle each request in its own thread
        std::thread([clientSock]() { handleClient(clientSock); }).detach();
    }

    return 0;
}
