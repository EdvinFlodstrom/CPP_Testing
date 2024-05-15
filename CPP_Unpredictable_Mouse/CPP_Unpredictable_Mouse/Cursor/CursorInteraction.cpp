#include <Windows.h>
#include "CursorInteraction.h"
#include "../Random/Random.h"

void AdjustCursorPosition(std::pair<int, int> position)
{
	std::vector<int> randomValues = GetRandomValues(-400, 400, 2);

	if (randomValues.size() != 2)
	{
		return;
	}

	SetCursorPos(position.first + randomValues[0], position.second + randomValues[1]);
}

std::pair<int, int> GetCursorPosition()
{
	POINT cursorPosition;

	return GetCursorPos(&cursorPosition) ? std::make_pair(cursorPosition.x, cursorPosition.y) : std::make_pair((long)0, (long)0);
}

void Await(int duration)
{
	Sleep(duration);
}