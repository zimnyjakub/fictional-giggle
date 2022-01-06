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

    model = new ProcessListModel(this);

    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0, 60);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

ScrabVision::~ScrabVision() {
    delete ui;
}

void ScrabVision::on_refreshListButton_clicked() {
    auto windows = GetVisibleWindows();
    if (model->rowCount() > 0) {
        model->removeRows(0, model->rowCount());
    }

    for (const auto &window: windows) {

        model->insertRows(0, 1);
        auto ix = model->index(0, 0);

        model->setData(ix, window.first, Qt::EditRole);
        ix = model->index(0, 1);
        model->setData(ix, window.second, Qt::EditRole);
    }
}

#endif //SCRABVISION_SCRABVISION_CPP


