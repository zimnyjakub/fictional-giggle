//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_WINDOWUTIL_CPP
#define SCRABVISION_WINDOWUTIL_CPP


#include <Windows.h>
#include <tuple>
#include <vector>
#include <string>

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
    auto vec = (std::vector<std::tuple<int,std::string>>*)lParam;
    wchar_t buff[255];
    DWORD pid;

    if (IsWindowVisible(hWnd)) {
        GetWindowText(hWnd, buff, 254);
        GetWindowThreadProcessId(hWnd, &pid);

        std::wstring ws(buff);
        std::string test( ws.begin(), ws.end() );
        vec->emplace_back((int)pid, test);
    }
    return TRUE;
}


std::vector<std::tuple<int, std::string>> GetVisibleWindows() {
    auto vec = std::vector<std::tuple<int, std::string>>();

    EnumWindows(EnumWindowsProc, (LPARAM)&vec);

    return vec;
}


#endif //SCRABVISION_WINDOWUTIL_CPP
