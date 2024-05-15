#include <Windows.h>
#include <iostream>
#include <vector>
#include "Cursor/CursorInteraction.h"
#include "Random/Random.h"

int main()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			break;

		AdjustCursorPosition(GetCursorPosition());
		Await(GetRandomValues(200, 750, 1)[0]);
	}

	return 0;
}