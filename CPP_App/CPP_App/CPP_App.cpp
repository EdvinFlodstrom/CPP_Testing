#include <Windows.h>
#include <thread>
#include <atomic>

std::atomic<bool> exitProgram{ false };
std::atomic<bool> clicking{ false };

static void SimulateLeftClick()
{
	while (clicking)
	{
		for (int i = 0; i < 10; i++)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		Sleep(100);
	}
}

int main()
{
	std::thread clickThread;

	while (!exitProgram)
	{
		if (GetAsyncKeyState('Q') & 0x8000)
			exitProgram = true;

		if (GetAsyncKeyState('X') & 0x8000)
		{
			if (clicking)
			{
				clicking = false;
				if (clickThread.joinable())
					clickThread.join();
			}
			else
			{
				clicking = true;
				clickThread = std::thread(SimulateLeftClick);
			}
		}
		Sleep(500);
	}

	if (clickThread.joinable())
	{
		clickThread.join();
	}
	return 0;
}
