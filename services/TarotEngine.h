#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
#include <ctime>
#include "TarotDeck.h"          // FIX: correct path from project root
#include "../models/User.h"                  // FIX: correct path from project root
#include "../utils/TarotCombinations.h"      // TarotReading struct + generateTarotMap()

// -----------------------------------------------------------------------------
//  ReadingRecord  — stored in session history
// -----------------------------------------------------------------------------
struct ReadingRecord {
    std::string timestamp;
    std::string pastCard;
    std::string presentCard;
    std::string futureCard;
    std::string mood;
    TarotReading reading;
};

// -----------------------------------------------------------------------------
//  TarotEngine
// -----------------------------------------------------------------------------
class TarotEngine {
private:
    TarotDeck                  deck;
    TarotMap                   combinations;
    std::vector<ReadingRecord> history;

    static std::string currentTimestamp() {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        char buf[32];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d  %H:%M", std::localtime(&t));
        return std::string(buf);
    }

    static std::string wrap(const std::string& text, int width = 62, int indent = 4) {
        std::string pad(indent, ' ');
        std::istringstream words(text);
        std::string word, line, result;
        while (words >> word) {
            if (!line.empty() && (int)(line.size() + 1 + word.size()) > width) {
                result += pad + line + "\n";
                line = word;
            } else {
                if (!line.empty()) line += ' ';
                line += word;
            }
        }
        if (!line.empty()) result += pad + line + "\n";
        return result;
    }

    // FIX: was bare Mood:: — must be User::Mood:: (Mood is scoped inside User class)
    static std::string moodOpening(const User& user) {
        switch (user.getMood()) {
            case User::Mood::Happy:
                return "The cards are bright today — your open, joyful energy is a gift "
                       "to this reading. Let's see what the spread reveals.";
            case User::Mood::Sad:
                return "I hear the weight you are carrying. The cards do not judge it — "
                       "they simply illuminate the path forward. Let's look together.";
            case User::Mood::Neutral:
                return "You arrive in a centred state, and that is actually ideal for a "
                       "reading. Still water reflects clearly. Let's see what surfaces.";
            case User::Mood::Confused:
                return "The cards often speak most clearly to confusion — uncertainty is "
                       "not a weakness, it is an open door. Let's find some light.";
            case User::Mood::Excited:
                return "Your energy is electric right now, and the cards can feel it. "
                       "Let's channel that momentum and see where it is pointed.";
        }
        return "Let's see what the cards have to say.";
    }

    static std::string cardSymbol(const std::string& name) {
        if (name == "The Fool")            return "[0]";
        if (name == "The Magician")        return "[M]";
        if (name == "The High Priestess")  return "[P]";
        if (name == "The Empress")         return "[Ep]";
        if (name == "The Emperor")         return "[Em]";
        if (name == "The Lovers")          return "[L]";
        if (name == "The Chariot")         return "[Ch]";
        if (name == "Strength")            return "[St]";
        if (name == "The Hermit")          return "[He]";
        if (name == "The Star")            return "[*]";
        return "[*]";
    }

    // FIX: renamed from indexToCard to avoid collision with the Card class name.
    // The ::Card prefix refers to the Card enum in TarotCombinations.h, not the Card class.
    static CardId indexToCardEnum(int idx) {
        return static_cast<CardId>(idx);
    }

    static void printDoubleLine() {
        std::cout << "+==================================================================+\n";
    }
    static void printDoubleLineBottom() {
        std::cout << "+==================================================================+\n";
    }
    static void printSingleLine() {
        std::cout << "+------------------------------------------------------------------+\n";
    }
    static void printCentred(const std::string& text, char fill = ' ') {
        const int width = 66;
        int padding = (width - (int)text.size()) / 2;
        if (padding < 1) padding = 1;
        std::cout << "|" << std::string(padding, fill)
                  << text
                  << std::string(width - padding - (int)text.size(), fill)
                  << "|\n";
    }

    void printCardBlock(const std::string& label,
                        const std::string& cardName,
                        const std::string& meaning) const {
        std::cout << "\n  " << cardSymbol(cardName) << "  " << label << ":  " << cardName << "\n\n";
        std::cout << wrap(meaning, 62, 6);
        std::cout << "\n";
    }

public:
    TarotEngine() : combinations(generateTarotMap()) {}

    void performReading(User& user, int pastIndex, int presentIndex, int futureIndex) {

        // FIX: deck.getCardName() now exists (added to TarotDeck.h)
        std::string pastCard    = deck.getCardName(pastIndex);
        std::string presentCard = deck.getCardName(presentIndex);
        std::string futureCard  = deck.getCardName(futureIndex);

        TarotKey key = { indexToCardEnum(pastIndex),
                         indexToCardEnum(presentIndex),
                         indexToCardEnum(futureIndex) };

        TarotReading reading;
        if (combinations.count(key) > 0) {
            reading = combinations.at(key);
        } else {
            reading = {
                "The cards are quiet about your past — sometimes what shaped us "
                "resists easy words. Trust what you carry.",
                "Your present is uncharted territory in the deck. That is not a "
                "warning — it is an invitation to write your own meaning.",
                "The future here is open, like a page not yet written. That is "
                "never a bad sign.",
                "The cards are aligning in a rare and unique configuration. "
                "Trust your intuition above all else in this reading.",
                "Suggestion: Sit quietly and ask yourself what you already know "
                "about this situation. Write it down before seeking outside answers."
            };
        }

        // FIX: was static_cast<Mood> — must be static_cast<User::Mood>
        std::string colouredSynergy = applyMoodTone(reading.synergy,
                                                    static_cast<User::Mood>(user.getMood()));

        std::cout << "\n\n";
        printDoubleLine();
        printCentred("T A R O T   R E A D E R");
        printCentred(currentTimestamp());
        printSingleLine();
        printCentred("Reading for  " + user.getName());
        printCentred("Mood:  " + user.getMoodString());
        printDoubleLineBottom();

        std::cout << "\n" << wrap(moodOpening(user), 66, 2) << "\n";

        std::cout << "  +--------------+   +---------------+   +--------------+\n";
        std::cout << "  |   P A S T    |   |  P R E S E N T |   |  F U T U R E |\n";
        std::cout << "  +--------------+   +---------------+   +--------------+\n\n";

        printCardBlock("PAST",    pastCard,    reading.past);
        printCardBlock("PRESENT", presentCard, reading.present);
        printCardBlock("FUTURE",  futureCard,  reading.future);

        std::cout << "  -----------------------------------------------------\n";
        std::cout << "  [>>]  THE READER'S INTERPRETATION\n\n";
        std::cout << wrap(colouredSynergy, 62, 6);

        std::cout << "\n  -----------------------------------------------------\n";
        std::cout << "  [!]  GUIDANCE FOR YOU\n\n";
        std::cout << wrap(reading.suggestion, 62, 6);

        std::cout << "\n  -----------------------------------------------------\n\n";

        history.push_back({
            currentTimestamp(),
            pastCard, presentCard, futureCard,
            user.getMoodString(),
            reading
        });
    }

    void printHistory() const {
        if (history.empty()) {
            std::cout << "\n  No readings have been performed yet.\n\n";
            return;
        }
        std::cout << "\n\n";
        printDoubleLine();
        printCentred("R E A D I N G   H I S T O R Y");
        printDoubleLineBottom();
        for (int i = 0; i < (int)history.size(); ++i) {
            const auto& r = history[i];
            std::cout << "\n  #" << (i + 1) << "  " << r.timestamp << "   (" << r.mood << ")\n";
            std::cout << "      Past:    " << r.pastCard    << "\n";
            std::cout << "      Present: " << r.presentCard << "\n";
            std::cout << "      Future:  " << r.futureCard  << "\n";
            std::cout << "\n      Synergy:\n"  << wrap(r.reading.synergy,    58, 8);
            std::cout << "\n      Guidance:\n" << wrap(r.reading.suggestion, 58, 8);
            if (i < (int)history.size() - 1)
                std::cout << "\n  ...................................................\n";
        }
        std::cout << "\n";
        printDoubleLineBottom();
        std::cout << "\n";
    }

    void clearHistory() { history.clear(); std::cout << "  Reading history cleared.\n"; }
    int  readingCount() const { return (int)history.size(); }

    std::string getSynergy(int p, int pr, int f) const {
        TarotKey key = { indexToCardEnum(p), indexToCardEnum(pr), indexToCardEnum(f) };
        auto it = combinations.find(key);
        return (it != combinations.end()) ? it->second.synergy : "";
    }
    std::string getSuggestion(int p, int pr, int f) const {
        TarotKey key = { indexToCardEnum(p), indexToCardEnum(pr), indexToCardEnum(f) };
        auto it = combinations.find(key);
        return (it != combinations.end()) ? it->second.suggestion : "";
    }
    std::string getPastMeaning(int p, int pr, int f) const {
        TarotKey key = { indexToCardEnum(p), indexToCardEnum(pr), indexToCardEnum(f) };
        auto it = combinations.find(key);
        return (it != combinations.end()) ? it->second.past : "";
    }
    std::string getPresentMeaning(int p, int pr, int f) const {
        TarotKey key = { indexToCardEnum(p), indexToCardEnum(pr), indexToCardEnum(f) };
        auto it = combinations.find(key);
        return (it != combinations.end()) ? it->second.present : "";
    }
    std::string getFutureMeaning(int p, int pr, int f) const {
        TarotKey key = { indexToCardEnum(p), indexToCardEnum(pr), indexToCardEnum(f) };
        auto it = combinations.find(key);
        return (it != combinations.end()) ? it->second.future : "";
    }
};
