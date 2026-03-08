#!/bin/bash
echo "Compiling Tarot Card Reader..."
g++ -std=c++17 -o tarot main.cpp models/Card.cpp services/TarotDeck.cpp \
    -I. -Imodels -Iservices -Iutils

if [ $? -eq 0 ]; then
    echo ""
    echo "Build successful! Run ./tarot to start."
    mkdir -p data
else
    echo ""
    echo "Build failed. Check errors above."
fi
