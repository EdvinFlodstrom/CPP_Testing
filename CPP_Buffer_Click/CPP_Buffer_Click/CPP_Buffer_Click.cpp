#include <Windows.h>
#include <vector>

static std::pair<int, int> GetCursorPosition()
{
    POINT cursorPosition;

    return GetCursorPos(&cursorPosition) ? std::make_pair(cursorPosition.x, cursorPosition.y) : std::make_pair((long)0, (long)0);
}

static void SimulateLeftClick()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

static void ClickAtGivenPosition(std::pair<int, int> positionToClickAt)
{
    SetCursorPos(positionToClickAt.first, positionToClickAt.second);
    SimulateLeftClick();
}

int main()
{
    std::vector<std::pair<int, int>> positionOfSavedClicks;
    bool savingClicks = false;

    while (true)
    {
        if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            if (!savingClicks)
            {
                Sleep(200);
                positionOfSavedClicks.clear(); // Clear the vector to avoid unexpected behaviour.

                SetCursorPos(0, 0); // Set the cursor position so that it becomes obvious when the program is saving click positions.

                savingClicks = true;

                while (true)
                {
                    if (GetAsyncKeyState(0x02) & 0x8000) // Right clicks save a left click at the cursor's current position.
                    {
                        Sleep(200);
                        positionOfSavedClicks.push_back(GetCursorPosition());
                    }

                    Sleep(75);

                    if (GetAsyncKeyState(VK_RETURN) & 0x8000)
                    {
                        SetCursorPos(200, 200);
                        break;
                    }
                }
            }
            else
            {
                savingClicks = false;

                Sleep(200);

                for (const auto& element : positionOfSavedClicks) // For each saved position, simulate a left click.
                {
                    ClickAtGivenPosition(element);
                    Sleep(10);
                }
            }
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;

        Sleep(125);
    }

    return 0;
}