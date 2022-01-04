#include <QApplication>
#include <QPushButton>
#include <Windows.h>
#include <string>
#include <stdio.h>

#include "scrabvision.h"

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
    wchar_t buff[255];
    DWORD pid ;

    if (IsWindowVisible(hWnd)) {
        GetWindowText(hWnd, buff,254);
        GetWindowThreadProcessId(hWnd, &pid);
        printf("pid: %lu %ls\n",pid, buff);
    }
    return TRUE;
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setStyle("fusion");

    ScrabVision w;
    w.show();

    return QApplication::exec();
//    EnumWindows(EnumWindowsProc, 0);

    return 0;
}




