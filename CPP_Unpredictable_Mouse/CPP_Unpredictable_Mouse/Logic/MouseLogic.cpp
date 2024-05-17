#include <Windows.h>
#include <iostream>
#include <vector>
#include "MouseLogic.h"
#include "../Cursor/CursorInteraction.h"
#include "../Random/Random.h"

int MoveMouseUnpredictably()
{
	const int POSITION_RANDOM_NUMBER_RANGE = 250;
	const int AWAIT_MIN_MS = 200;
	const int AWAIT_MAX_MS = 750;

	while (true)
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			break;

		AdjustCursorPosition(GetCursorPosition(), -POSITION_RANDOM_NUMBER_RANGE, POSITION_RANDOM_NUMBER_RANGE);
		Await(GetRandomValues(AWAIT_MIN_MS, AWAIT_MAX_MS, 1)[0]);
	}

	return 0;
}


int MoveMouseOnClick()
{
	const int MOUSE_ADJUST_RANDOM_NUMBER_RANGE = 250;
	const int AWAIT_DURATION = 10;
	bool mouseDown = false;

	while (true)
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) // Down arrow to exit program
			break;

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		{
			if (!mouseDown)
			{
				AdjustCursorPosition(GetCursorPosition(), -MOUSE_ADJUST_RANDOM_NUMBER_RANGE, MOUSE_ADJUST_RANDOM_NUMBER_RANGE);
				mouseDown = true;
			}
		}
		else
		{
			mouseDown = false;
		}

		Await(AWAIT_DURATION);
	}

	return 0;
}