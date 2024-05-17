#include <Windows.h>
#include <iostream>
#include <vector>
#include "Logic.h"
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