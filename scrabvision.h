//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_SCRABVISION_H
#define SCRABVISION_SCRABVISION_H

#include "process_list_model.h"

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


    ~ScrabVision() override;

private slots:
    void on_refreshListButton_clicked();

private:
    Ui::ScrabVision *ui;
    ProcessListModel *model;
};


#endif //SCRABVISION_SCRABVISION_H
