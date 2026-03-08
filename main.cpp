#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>        // FIX 1: was missing — needed for std::setw, std::left
#include <filesystem>
#include <algorithm>
#include <chrono>         // FIX 2: was missing — needed for timestamp in saveReadingToFile
#include <ctime>          // FIX 3: was missing — needed for std::strftime, std::localtime
#include "models/User.h"
#include "services/TarotEngine.h"  // FIX 4: was "services/TarotEngine.h" — TarotEngine.h lives next to main.cpp

#ifdef _WIN32
#include <windows.h>  // SetConsoleOutputCP for Windows encoding
#endif

namespace fs = std::filesystem;

// -----------------------------------------------------------------------------
//  Terminal helpers
// -----------------------------------------------------------------------------

static void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void pressEnterToContinue() {
    std::cout << "\n  Press ENTER to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

static void printBanner() {
    std::cout << R"(
  +==================================================================+
  |                                                                  |
  |        [P]   T A R O T   C A R D   R E A D E R   [*]              |
  |                                                                  |
  |          Unveil the past . Illuminate the present               |
  |                   Navigate the future                           |
  |                                                                  |
  +==================================================================+
)" << "\n";
}

// -----------------------------------------------------------------------------
//  Safe integer input within [lo, hi]
// -----------------------------------------------------------------------------
static int getInt(const std::string& prompt, int lo, int hi) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= lo && value <= hi) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  ⚠  Please enter a number between " << lo << " and " << hi << ".\n";
    }
}

// -----------------------------------------------------------------------------
//  Safe name input (non-empty, trimmed)
// -----------------------------------------------------------------------------
static std::string getName(const std::string& prompt) {
    std::string name;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, name);
        auto start = name.find_first_not_of(" \t");
        auto end   = name.find_last_not_of(" \t");
        if (start != std::string::npos) {
            name = name.substr(start, end - start + 1);
            return name;
        }
        std::cout << "  ⚠  Name cannot be empty.\n";
    }
}

// -----------------------------------------------------------------------------
//  Card table  —  single source of truth in main.cpp
// -----------------------------------------------------------------------------
static const char* CARD_NAMES[11] = {
    "",                    // 0 unused — cards are 1-indexed
    "The Fool",
    "The Magician",
    "The High Priestess",
    "The Empress",
    "The Emperor",
    "The Lovers",
    "The Chariot",
    "Strength",
    "The Hermit",
    "The Star"
};

static const char* CARD_SYMBOLS[11] = {
    "", "[0]", "[M]", "[P]", "[Ep]", "[Em]", "[L]", "[Ch]", "[St]", "[He]", "[*]"
};

// -----------------------------------------------------------------------------
//  Card picker — shows full deck, enforces no duplicates
// -----------------------------------------------------------------------------
static void printCardMenu(int exclude1 = -1, int exclude2 = -1) {
    std::cout << "\n  +------------------------------------------+\n";
    std::cout <<   "  |   The cards are laid face down before you |\n";
    std::cout <<   "  |   Choose a number to draw your card...    |\n";
    std::cout <<   "  +------------------------------------------+\n";
    // Print numbers only — no names visible until the reading
    std::cout << "  |                                          |\n";
    std::cout << "  |  ";
    for (int i = 1; i <= 10; ++i) {
        bool taken = (i == exclude1 || i == exclude2);
        if (taken)
            std::cout << " [.]";
        else
            std::cout << " [" << i << "] ";
        if (i == 5) std::cout << "\n  |  ";
    }
    std::cout << "\n  |                                          |\n";
    std::cout << "  +------------------------------------------+\n";
}

static int pickCard(const std::string& label, int exclude1 = -1, int exclude2 = -1) {
    printCardMenu(exclude1, exclude2);
    int card;
    while (true) {
        card = getInt("  " + label + " (1-10): ", 1, 10);
        if (card == exclude1 || card == exclude2) {
            std::cout << "  That card is already in your spread. Choose a different one.\n";
        } else {
            // Reveal the card dramatically
            std::cout << "\n  +------------------------------------------+\n";
            std::cout <<   "  |  You have drawn...                       |\n";
            std::cout <<   "  |                                          |\n";
            std::cout << "  |     >> " << std::left << std::setw(34) << CARD_NAMES[card] << "|\n";
            std::cout <<   "  |                                          |\n";
            std::cout <<   "  +------------------------------------------+\n\n";
            return card;
        }
    }
}

// -----------------------------------------------------------------------------
//  File persistence
// -----------------------------------------------------------------------------
static void ensureDataDir() {
    if (!fs::exists("data"))
        fs::create_directory("data");
}

static void saveReadingToFile(const User&         user,
                               int                pastIdx,
                               int                presentIdx,
                               int                futureIdx,
                               const TarotEngine& engine) {
    ensureDataDir();
    std::ofstream out("data/history.txt", std::ios::app);
    if (!out.is_open()) {
        std::cout << "  ⚠  Could not open data/history.txt for writing.\n";
        return;
    }

    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    char buf[32];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", std::localtime(&t));

    out << "==========================================\n";
    out << "Date     : " << buf                                                    << "\n";
    out << "Name     : " << user.getName()                                         << "\n";
    out << "Mood     : " << user.getMoodString()                                   << "\n";
    out << "------------------------------------------\n";
    out << "Past     : " << CARD_NAMES[pastIdx]                                    << "\n";
    out << "Present  : " << CARD_NAMES[presentIdx]                                 << "\n";
    out << "Future   : " << CARD_NAMES[futureIdx]                                  << "\n";
    out << "------------------------------------------\n";
    out << "Synergy  :\n" << engine.getSynergy(pastIdx, presentIdx, futureIdx)    << "\n";
    out << "Guidance :\n" << engine.getSuggestion(pastIdx, presentIdx, futureIdx) << "\n";
    out << "\n";
    out.close();
}

static void viewSavedHistory() {
    std::ifstream in("data/history.txt");
    if (!in.is_open() || in.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "\n  No saved readings found in data/history.txt\n";
        return;
    }
    std::cout << "\n";
    std::string line;
    while (std::getline(in, line))
        std::cout << "  " << line << "\n";
    in.close();
}

static void clearSavedHistory() {
    ensureDataDir();
    std::ofstream out("data/history.txt", std::ios::trunc);
    out.close();
    std::cout << "  ✓  Saved history cleared.\n";
}

// -----------------------------------------------------------------------------
//  Mood selection
// -----------------------------------------------------------------------------
static int selectMood() {
    std::cout << "\n  +---------------------------------------+\n";
    std::cout <<   "  |       How are you feeling today?      |\n";
    std::cout <<   "  +---------------------------------------+\n";
    std::cout <<   "  |  [H]  1.  Happy                        |\n";
    std::cout <<   "  |  [S]  2.  Sad                          |\n";
    std::cout <<   "  |  [N]  3.  Neutral                      |\n";
    std::cout <<   "  |  [C]  4.  Confused                     |\n";
    std::cout <<   "  |  [E]  5.  Excited                      |\n";
    std::cout <<   "  +---------------------------------------+\n";
    return getInt("  Your mood (1-5): ", 1, 5);
}

// -----------------------------------------------------------------------------
//  Main menu
// -----------------------------------------------------------------------------
static void printMainMenu(const std::string& userName, int sessionCount) {
    std::cout << "\n  Welcome back, " << userName << ".\n";
    if (sessionCount > 0)
        std::cout << "  Readings this session: " << sessionCount << "\n";
    std::cout << "\n";
    std::cout << "  +---------------------------------------+\n";
    std::cout <<   "  |              M A I N  M E N U        |\n";
    std::cout <<   "  +---------------------------------------+\n";
    std::cout <<   "  |  [*]  1.  New Reading                  |\n";
    std::cout <<   "  |  [~]  2.  Session History              |\n";
    std::cout <<   "  |  [>]  3.  View Saved History           |\n";
    std::cout <<   "  |  [x]   4.  Clear Saved History          |\n";
    std::cout <<   "  |  [u]  5.  Change Name                  |\n";
    std::cout <<   "  |  [q]  0.  Exit                         |\n";
    std::cout <<   "  +---------------------------------------+\n";
}

// -----------------------------------------------------------------------------
//  main()
// -----------------------------------------------------------------------------
int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);  // Enable UTF-8 output on Windows
    SetConsoleCP(CP_UTF8);
#endif
    clearScreen();
    printBanner();

    std::cout << "  Before we begin, I would like to know who I am reading for.\n\n";
    std::string userName = getName("  Your name: ");

    TarotEngine engine;
    User user;
    user.setName(userName);

    int menuChoice = -1;

    do {
        clearScreen();
        printBanner();
        printMainMenu(userName, engine.readingCount());
        menuChoice = getInt("\n  Choose an option: ", 0, 5);

        switch (menuChoice) {

            case 1: {   // -- New Reading --------------------------------------
                clearScreen();
                printBanner();

                int moodChoice = selectMood();
                // FIX 5: cast to User::Mood (scoped inside User class), not bare Mood
                user.setMood(static_cast<User::Mood>(moodChoice));

                std::cout << "\n  Now choose three cards for your spread.\n";
                int pastIdx    = pickCard("Card for your PAST",    -1,      -1);
                int presentIdx = pickCard("Card for your PRESENT", pastIdx, -1);
                int futureIdx  = pickCard("Card for your FUTURE",  pastIdx, presentIdx);

                engine.performReading(user, pastIdx, presentIdx, futureIdx);

                saveReadingToFile(user, pastIdx, presentIdx, futureIdx, engine);
                std::cout << "  ✓  Reading saved to data/history.txt\n";

                pressEnterToContinue();
                break;
            }

            case 2: {   // -- Session History -----------------------------------
                clearScreen();
                printBanner();
                engine.printHistory();
                pressEnterToContinue();
                break;
            }

            case 3: {   // -- View Saved History --------------------------------
                clearScreen();
                printBanner();
                viewSavedHistory();
                pressEnterToContinue();
                break;
            }

            case 4: {   // -- Clear Saved History -------------------------------
                clearScreen();
                printBanner();
                std::cout << "\n  Are you sure you want to clear all saved readings?\n";
                int confirm = getInt("  (1: Yes, 0: No): ", 0, 1);
                if (confirm == 1)
                    clearSavedHistory();
                else
                    std::cout << "  Cancelled.\n";
                pressEnterToContinue();
                break;
            }

            case 5: {   // -- Change Name ---------------------------------------
                clearScreen();
                printBanner();
                std::cout << "\n  Current name: " << userName << "\n";
                userName = getName("  New name: ");
                user.setName(userName);
                std::cout << "  ✓  Name updated to " << userName << ".\n";
                pressEnterToContinue();
                break;
            }

            case 0:
                break;
        }

    } while (menuChoice != 0);

    // -- Farewell -------------------------------------------------------------
    clearScreen();
    printBanner();
    std::cout << "\n  Thank you for your reading today, " << userName << ".\n";
    std::cout << "  The cards will be here when you return. [P]\n\n";
    if (engine.readingCount() > 0)
        std::cout << "  " << engine.readingCount()
                  << " reading(s) saved to data/history.txt\n\n";

    return 0;
}
