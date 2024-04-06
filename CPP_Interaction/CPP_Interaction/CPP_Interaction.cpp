#include <Windows.h>
#include <iostream>
#include <conio.h>

static void LoopThings();
static void LogThings();
static std::pair<int, int> GetCursorPosition();

int main()
{
	std::cout << "This program logs the position of the cursor every time you input a key. "
		<< "Press 'Enter' at any time to exit." << std::endl;

	LoopThings();
	
	return 0;
}

static void LoopThings()
{
	char input;

	while (input = _getch())
	{
		if (input == '\r')
			break;

		LogThings();
	}
}

static void LogThings()
{
	std::pair<int, int> currentCursorPosition = GetCursorPosition();
	std::cout << "The cursor's current position is: " << "X: " << currentCursorPosition.first
		<< ", Y: " << currentCursorPosition.second << "." << std::endl;
}

static std::pair<int, int> GetCursorPosition()
{
	POINT cursorPosition;
	std::pair<int, int> currentCursorPosValues = std::pair<int, int>(0,0);

	if (GetCursorPos(&cursorPosition))
	{
		currentCursorPosValues.first = cursorPosition.x;
		currentCursorPosValues.second = cursorPosition.y;
	}
	return currentCursorPosValues;
}