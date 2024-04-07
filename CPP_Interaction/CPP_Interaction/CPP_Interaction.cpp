#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <functional>

static void LoopThings(std::function<void()> callback);
static void LogThings();
static std::pair<int, int> GetCursorPosition();
static void SimulateLeftClick(int numberOfClicks);
static void SimulateLeftClickAtSpecifiedCursorPositionOnCommand();

int main()
{
	//LoopThings([]() { LogThings(); });
	//LoopThings([]() { SimulateLeftClickAtSpecifiedCursorPositionOnCommand(); });
	LoopThings([]() { SimulateLeftClick(10); });
	
	return 0;
}

static void LoopThings(std::function<void()> callback)
{
	std::cout << "Press 'Enter' at any time to exit." << std::endl;

	while (_getch() != '\r')
	{
		callback();
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

static void SimulateLeftClick(int numberOfClicks)
{
	for (int i = 0; i < numberOfClicks; i++)
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
}

static void SimulateLeftClickAtSpecifiedCursorPositionOnCommand()
{
	std::cout << "First, press a key when you're hovering your cursor above a position. "
		<< "Then, press the key again after moving your cursor away from the position." << std::endl;

	char input = _getch();

	std::pair<int, int> savedCursorPosition = GetCursorPosition();

	while (_getch() != input) { }

	SetCursorPos(savedCursorPosition.first, savedCursorPosition.second);
	SimulateLeftClick(1);
}