//
// Created by zimny on 04.01.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScrabVision.h" resolved

#include "scrabvision.h"
#include "ui_scrabvision.h"
#include "process_list_model.h"
#include "windowutil.h"

#include <QAbstractItemView>
#include <string>


ScrabVision::ScrabVision(QWidget *parent) :
        QWidget(parent), ui(new Ui::ScrabVision) {

    ui->setupUi(this);

    model = new ProcessListModel(this);

    ui->processListView->setModel(model);
}

ScrabVision::~ScrabVision() {
    delete ui;
}

void ScrabVision::on_refreshListButton_clicked()
{
    auto windows = GetVisibleWindows();

    for (std::tuple<int,std::string> window : windows) {
        int pid;
        std::string name;
        std::tie(pid, name) = window;
        qDebug() << "pid: " << pid << "window: " << name.c_str();
    }
}


