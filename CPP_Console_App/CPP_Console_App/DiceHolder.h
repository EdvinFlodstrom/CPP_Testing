#pragma once

#include <string>

class DiceHolder
{
private:
    static int numberOfDices;
    std::pair<int, int> diceSize;

public:
    DiceHolder();
    DiceHolder(int numberOfSides);

    static std::string LogNumberOfDices();

    int ThrowDice();
};
