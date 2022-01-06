#include <QApplication>
#include <QPushButton>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "scrabvision.h"

using namespace cv;

int main(int argc, char *argv[]) {
    if ( argc != 2 )
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image;
    image = imread( argv[1], 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    waitKey(0);
    return 0;

//    QApplication a(argc, argv);
//    QApplication::setStyle("fusion");
//
//    ScrabVision w;
//    w.show();
//
//    return QApplication::exec();
}





