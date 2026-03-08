#pragma once
#include <string>
#include <map>
#include <vector>

class Card {
private:
    std::string name;
    // mood string -> list of possible meanings (supports random selection)
    std::map<std::string, std::vector<std::string>> moodMeanings;

public:
    Card() {}
    Card(const std::string& n) : name(n) {}

    // ── Getters ───────────────────────────────────────────────────────────────
    std::string getName() const { return name; }

    // ── Add a meaning for a mood (can add multiple per mood) ─────────────────
    void addMeaning(const std::string& mood, const std::string& meaning) {
        moodMeanings[mood].push_back(meaning);
    }

    // ── Get first (or only) meaning for a mood ────────────────────────────────
    std::string getMeaning(const std::string& mood) const {
        auto it = moodMeanings.find(mood);
        if (it != moodMeanings.end() && !it->second.empty())
            return it->second[0];
        return "No interpretation available for this mood.";
    }

    // ── Get a random meaning for a mood (used by Card.cpp) ───────────────────
    std::string getRandomMeaning(const std::string& mood) const;

    // ── Direct access to the meanings map (used by Card.cpp) ─────────────────
    const std::map<std::string, std::vector<std::string>>& getMoodMeanings() const {
        return moodMeanings;
    }
};
