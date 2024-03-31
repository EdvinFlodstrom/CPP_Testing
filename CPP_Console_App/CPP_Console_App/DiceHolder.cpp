#include "DiceHolder.h"
#include <sstream>
#include <random>

int DiceHolder::numberOfDices = 0;

DiceHolder::DiceHolder() : diceSize(1, 6)
{
    numberOfDices++;
}

DiceHolder::DiceHolder(int numberOfSides) : diceSize(1, numberOfSides)
{
    numberOfDices++;
}

std::string DiceHolder::LogNumberOfDices()
{
    return "The number of dices created was: " + std::to_string(numberOfDices);
}

int DiceHolder::ThrowDice()
{
    std::random_device rnd;
    std::mt19937 gen(rnd());

    std::uniform_int_distribution<> dis(diceSize.first, diceSize.second);

    return dis(gen);
}
