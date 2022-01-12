//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_SCRABVISION_H
#define SCRABVISION_SCRABVISION_H

#include "process_list_model.h"
#include "rect_area.h"

#include <QWidget>
#include <QStringListModel>
#include <Windows.h>


QT_BEGIN_NAMESPACE
namespace Ui { class ScrabVision; }
QT_END_NAMESPACE

class ScrabVision : public QWidget {
Q_OBJECT

public:
    explicit ScrabVision(QWidget *parent = nullptr);


    void addEntry(const QPair<int, QString> &entry);
    ~ScrabVision() override;

private slots:
    void on_refreshListButton_clicked();


    void on_useSelectedButton_clicked();

    void on_debugButton_clicked();

    void selectionChanged(QRect newSelection);

private:
    Ui::ScrabVision *ui;
    ProcessListModel *model;
    int selectedPid;
    HWND selectedHwnd;

    RectArea *rectArea;

    QImage croppedImage;

    cv::Mat originalCapture;
};


#endif //SCRABVISION_SCRABVISION_H
