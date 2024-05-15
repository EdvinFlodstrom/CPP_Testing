#pragma once

#include <vector>

void AdjustCursorPosition(std::pair<int, int> position);

std::pair<int, int> GetCursorPosition();

void Await(int duration);