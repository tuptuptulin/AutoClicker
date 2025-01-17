#include <iostream>
#include <Windows.h>

bool isCtrlHomePressed() {
    return GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_HOME) & 0x8000;
}

bool isCtrlEndPressed() {
    return GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_END) & 0x8000;
}

void clickMouse() {
    INPUT input = { 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    bool autoclickerActive = false;

    std::cout << "Ctrl+Home to start it | Ctrl+End to stop it!\n";

    while (true) {
        if (isCtrlHomePressed() && !autoclickerActive) {
            std::cout << "Activated\n";
            autoclickerActive = true;
        }

        if (isCtrlEndPressed() && autoclickerActive) {
            std::cout << "Stopped\n";
            autoclickerActive = false;
        }

        if (autoclickerActive) {
            clickMouse();
        }

        Sleep(10);
    }

    return 0;
}
