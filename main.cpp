#include <QApplication>
#include <QPushButton>
#include <Windows.h>

#include "scrabvision.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setStyle("fusion");

    ScrabVision w;
    w.show();

    return QApplication::exec();
}


