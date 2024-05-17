#include <vector>
#include <Windows.h>
#include <thread>
#include "KeyboardLogic.h"
#include "../Cursor/CursorInteraction.h"

const std::string MESSAGE = "My Mountainously Massively Major Message. ";

static void SimulateKeyboardInput(const std::string& message)
{
    std::vector<INPUT> inputs;

    auto addToBuffer = [&inputs](WORD keyCode, DWORD eventFlag)
        {
            INPUT input = { 0 }; // Initialize struct with default values
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = keyCode;
            input.ki.dwFlags = eventFlag;
            inputs.push_back(input);
        };

    for (char c : message)
    {
        if (isupper(c))
        {
            addToBuffer(VK_SHIFT, 0); // Press shift

            addToBuffer(VkKeyScanA(c), 0); // Press key
            addToBuffer(VkKeyScanA(c), KEYEVENTF_KEYUP); // Release key

            addToBuffer(VK_SHIFT, KEYEVENTF_KEYUP); // Release shift
        }
        else
        {
            addToBuffer(VkKeyScanA(c), 0); // Press key
            addToBuffer(VkKeyScanA(c), KEYEVENTF_KEYUP); // Release key
        }
    }

    SendInput(inputs.size(), inputs.data(), sizeof(INPUT));
}

int SimulateMessageKeyboardInput()
{
    const int AWAIT_DURATION = 100;

    std::thread keyboardThread;

    while (true)
    {
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) // Down arrow to exit program
            break;

        if (GetAsyncKeyState(VK_F10) & 0x8000)
        {
            // Thread still running?
            if (keyboardThread.joinable())
            {
                // Wait for the thread to complete
                keyboardThread.join();
            }
            else
            {
                keyboardThread = std::thread([]()
                    {
                        SimulateKeyboardInput(MESSAGE);
                    });
            }

            Await(AWAIT_DURATION);
        }
    }

    // Thread still running?
    if (keyboardThread.joinable())
    {
        // Wait for the thread to complete
        keyboardThread.join();
    }

    return 0;
}