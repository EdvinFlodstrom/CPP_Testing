#include <Windows.h>
#include <thread>
#include <atomic>

std::atomic<bool> exitProgram{ false };
std::atomic<bool> enableCheckingOfKeys{ false };
std::atomic<bool> clicking{ false };

static void SimulateLeftClick()
{
	while (!exitProgram)
	{
		if (clicking)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		else
		{
			Sleep(1000);
		}
		std::this_thread::yield();
	}
}

int main()
{
	std::thread clickThread(SimulateLeftClick);

	while (!exitProgram)
	{
		if (GetAsyncKeyState('Q') & 0x8000)
			exitProgram = true;

		if (GetAsyncKeyState('X') & 0x8000)
			clicking = true;

		else if (GetAsyncKeyState('Z') & 0x8000)
			clicking = false;

		Sleep(250);
	}

	if (clickThread.joinable())
	{
		clickThread.join();
	}
	return 0;
}
