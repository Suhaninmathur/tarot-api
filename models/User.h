#pragma once
#include <string>

class User {
public:
    // IMPORTANT: values start at 1 to match the menu input (1=Happy … 5=Excited).
    // main.cpp does:  static_cast<User::Mood>(moodChoice)  where moodChoice is 1-5.
    // If the enum started at 0 every mood would be shifted by one.
    enum Mood {
        Happy    = 1,
        Sad      = 2,
        Neutral  = 3,
        Confused = 4,
        Excited  = 5
    };

    User() : mood(Mood::Neutral) {}

    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }

    void setMood(Mood m) { mood = m; }
    Mood getMood() const { return mood; }

    std::string getMoodString() const {
        switch (mood) {
            case Mood::Happy:    return "Happy";
            case Mood::Sad:      return "Sad";
            case Mood::Neutral:  return "Neutral";
            case Mood::Confused: return "Confused";
            case Mood::Excited:  return "Excited";
        }
        return "Unknown";
    }

private:
    std::string name;
    Mood mood;
};
