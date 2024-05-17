#pragma once

#include <vector>

void AdjustCursorPosition(std::pair<int, int> position, int minRandomNumber, int maxRandomNumber);

std::pair<int, int> GetCursorPosition();

void Await(int duration);