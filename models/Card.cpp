#include "Card.h"
#include <cstdlib>   // std::rand
#include <ctime>     // std::time (seed once in main if needed)

// Returns a random meaning for the given mood.
// Falls back to the first meaning, then to a default string.
std::string Card::getRandomMeaning(const std::string& mood) const {
    auto it = moodMeanings.find(mood);
    if (it != moodMeanings.end() && !it->second.empty()) {
        const auto& vec = it->second;
        int idx = std::rand() % static_cast<int>(vec.size());
        return vec[idx];
    }
    return "Meaning not found.";
}
