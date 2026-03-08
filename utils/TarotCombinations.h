#ifndef TAROT_COMBINATIONS_H
#define TAROT_COMBINATIONS_H

#include <string>
#include <map>
#include <tuple>
#include "../models/User.h"
#include "../models/TarotCard.h"

enum CardId {
    TheFool = 1, TheMagician, TheHighPriestess, TheEmpress,
    TheEmperor, TheLovers, TheChariot, Strength, TheHermit, TheStar
};

using TarotKey = std::tuple<CardId,CardId,CardId>;
using TarotMap = std::map<TarotKey, TarotReading>;

inline std::string applyMoodTone(const std::string& text, User::Mood mood) {
    switch(mood) {
        case User::Mood::Happy:    return "The cards are bright today â€” " + text;
        case User::Mood::Sad:      return "I hear the weight you are carrying â€” " + text;
        case User::Mood::Neutral:  return text;
        case User::Mood::Confused: return "The cards often speak to confusion â€” " + text;
        case User::Mood::Excited:  return "Your energy is electric right now â€” " + text;
    }
    return text;
}

// Defined in TarotCombinations.cpp
TarotMap generateTarotMap();

#endif // TAROT_COMBINATIONS_H