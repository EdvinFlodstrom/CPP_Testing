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
        if (GetAsyncKeyState(VK_UP) & 0x8000) // Up arrow inputs enter click location saving mode
        {
            if (!savingClicks)
            {
                Sleep(200);
                positionOfSavedClicks.clear(); // Clear the vector to avoid unexpected behaviour.

                SetCursorPos(0, 0); // Set the cursor position so that it becomes obvious when the program is saving click positions.

                savingClicks = true;

                while (true)
                {
                    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) // Right arrow inputs save a left click at the cursor's current position.
                    {
                        Sleep(200);
                        positionOfSavedClicks.push_back(GetCursorPosition());
                    }

                    if (GetAsyncKeyState(VK_LEFT) & 0x8000) // Left arrow inputs exit click location saving mode
                    {
                        SetCursorPos(200, 200);
                        break;
                    }

                    Sleep(75);
                }
            }
            else
            {
                savingClicks = false;

                Sleep(200);

                for (const auto& element : positionOfSavedClicks) // For each saved position, simulate a left click.
                {
                    ClickAtGivenPosition(element);
                    Sleep(5);
                }
            }
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000) // Down arrow inputs exit the program
            break;

        Sleep(125);
    }

    return 0;
}