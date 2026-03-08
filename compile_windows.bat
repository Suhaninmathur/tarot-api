@echo off
echo Compiling Tarot Card Reader...
g++ -std=c++17 -o tarot.exe main.cpp models/Card.cpp services/TarotDeck.cpp -I. -Imodels -Iservices -Iutils
if %errorlevel% == 0 (
    echo.
    echo Build successful! Run tarot.exe to start.
    mkdir data 2>nul
) else (
    echo.
    echo Build failed. Check errors above.
)
pause
