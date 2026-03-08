#pragma once
#include <vector>
#include <stdexcept>
#include "../models/Card.h"   // Card lives in same services/ folder

class TarotDeck {
private:
    std::vector<Card> cards;   // 0-based internally

public:
    TarotDeck() { initDeck(); }   // auto-init on construction so callers never forget

    void initDeck();

    // ── Primary accessor — 1-based index (matches menu choices 1-10) ─────────
    Card getCard(int index) const {
        // Convert 1-based public index → 0-based internal index
        int i = index - 1;
        if (i < 0 || i >= (int)cards.size())
            throw std::out_of_range(
                "Card index " + std::to_string(index) +
                " out of range (1-" + std::to_string(cards.size()) + ")");
        return cards[i];
    }

    // ── Convenience: get card name directly by 1-based index ─────────────────
    std::string getCardName(int index) const {
        return getCard(index).getName();
    }

    int size() const { return (int)cards.size(); }
};
