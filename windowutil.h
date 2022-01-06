//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_WINDOWUTIL_H
#define SCRABVISION_WINDOWUTIL_H


#include "pidname.h"

#include <Windows.h>
#include <tuple>
#include <utility>
#include <vector>
#include <string>


BOOL CALLBACK Gibberish(HWND hWnd, LPARAM lParam) {
    auto vec = (QVector<QPair<int,QString>> *) lParam;
    wchar_t buff[255];
    DWORD pid;

    if (IsWindowVisible(hWnd)) {
        GetWindowText(hWnd, buff, 254);
        GetWindowThreadProcessId(hWnd, &pid);

        std::wstring ws(buff);
        std::string test(ws.begin(), ws.end());
        vec->push_back(QPair<int,QString>(pid, QString::fromStdString(test)));
    }
    return TRUE;
}


QVector<QPair<int,QString>> GetVisibleWindows() {
    auto vec = QVector<QPair<int,QString>>();

    EnumWindows(Gibberish, (LPARAM) &vec);

    return vec;
}


#endif //SCRABVISION_WINDOWUTIL_H
