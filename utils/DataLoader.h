#pragma once
#include "../services/TarotDeck.h"   // TarotDeck uses Card internally

class DataLoader {
public:
    // Populates a deck with the 10 Major Arcana cards used by this application.
    // FIX: was using TarotCard(name, upright, reversed) constructor which does
    //      not exist. Card only has Card(name) + addMeaning(mood, text).
    //      DataLoader now calls deck.initDeck() which already contains all card
    //      data — so DataLoader just ensures the deck is ready.
    static void loadCards(TarotDeck& deck) {
        // TarotDeck::TarotDeck() calls initDeck() automatically.
        // This method exists for API compatibility — call it if you want to
        // explicitly trigger a reload (e.g. after clearning the deck).
        deck.initDeck();
    }
};
