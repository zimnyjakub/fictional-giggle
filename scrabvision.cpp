//
// Created by zimny on 04.01.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScrabVision.h" resolved
#ifndef SCRABVISION_SCRABVISION_CPP
#define SCRABVISION_SCRABVISION_CPP

#include "scrabvision.h"
#include "ui_scrabvision.h"
#include "process_list_model.h"
#include "windowutil.h"

#include <QAbstractItemView>
#include <string>


ScrabVision::ScrabVision(QWidget *parent) :
        QWidget(parent), ui(new Ui::ScrabVision) {

    ui->setupUi(this);

    auto windows = GetVisibleWindows();
    model = new ProcessListModel(windows, this);
    ui->tableView->setModel(model);
}

ScrabVision::~ScrabVision() {
    delete ui;
}

void ScrabVision::on_refreshListButton_clicked()
{
    auto windows = GetVisibleWindows();

    for (const auto& window : windows) {
        qDebug() << "pid: " << window.first << "window: " << window.second;
    }
}

#endif //SCRABVISION_SCRABVISION_CPP


