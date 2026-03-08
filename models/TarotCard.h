#pragma once
#include "Card.h"
#include <string>

// TarotReading holds all five fields produced by TarotCombinations.h
// and consumed by TarotEngine.h.  All five must be present or the
// struct initialisation in TarotCombinations.h will fail to compile.
struct TarotReading {
    std::string past;        // Reader's interpretation of the past card
    std::string present;     // Reader's interpretation of the present card
    std::string future;      // Reader's interpretation of the future card
    std::string synergy;     // Overall synthesis of all three cards
    std::string suggestion;  // Practical guidance for the querent
};
