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
#include <opencv2/opencv.hpp>

using namespace cv;


BOOL CALLBACK Gibberish(HWND hWnd, LPARAM lParam) {
    auto vec = (QVector<ProcessModel> *) lParam;
    wchar_t buff[255];
    DWORD pid;

    if (IsWindowVisible(hWnd)) {
        GetWindowText(hWnd, buff, 254);
        GetWindowThreadProcessId(hWnd, &pid);

        std::wstring ws(buff);
        std::string test(ws.begin(), ws.end());
        vec->push_back(ProcessModel{hWnd, static_cast<int>(pid), QString::fromStdString(test)});
    }
    return TRUE;
}


QVector<ProcessModel> GetVisibleWindows() {
    auto vec = QVector<ProcessModel>();

    EnumWindows(Gibberish, (LPARAM) &vec);

    return vec;
}

BITMAPINFOHEADER createBitmapHeader(int width, int height) {
    BITMAPINFOHEADER bi;

    // create a bitmap
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height;  //this is the line that makes it draw upside down or not
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    return bi;
}

Mat captureScreenMat(HWND hwnd) {
    Mat src;
    RECT rc;
    GetClientRect(hwnd, &rc);

    // get handles to a device context (DC)
    HDC hwindowDC = GetDC(hwnd);
    HDC hwindowCompatibleDC = CreateCompatibleDC(hwindowDC);
    SetStretchBltMode(hwindowCompatibleDC, COLORONCOLOR);

    // define scale, height and width
    int width = rc.right - rc.left;
    int height = rc.bottom - rc.top;

    // create mat object
    src.create(height, width, CV_8UC4);

    // create a bitmap
    HBITMAP hbwindow = CreateCompatibleBitmap(hwindowDC, width, height);
    BITMAPINFOHEADER bi = createBitmapHeader(width, height);

    // use the previously created device context with the bitmap
    SelectObject(hwindowCompatibleDC, hbwindow);
    PrintWindow(hwnd, hwindowCompatibleDC, PW_CLIENTONLY);

    GetDIBits(hwindowCompatibleDC, hbwindow, 0, height, src.data, (BITMAPINFO *) &bi,
              DIB_RGB_COLORS);            //copy from hwindowCompatibleDC to hbwindow

    // avoid memory leak
    DeleteObject(hbwindow);
    DeleteDC(hwindowCompatibleDC);
    ReleaseDC(hwnd, hwindowDC);

    return src;
}


#endif //SCRABVISION_WINDOWUTIL_H
