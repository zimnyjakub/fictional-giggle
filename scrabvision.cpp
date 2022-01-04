//
// Created by zimny on 04.01.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScrabVision.h" resolved

#include "scrabvision.h"
#include "ui_scrabvision.h"
#include "process_list_model.h"

#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>


ScrabVision::ScrabVision(QWidget *parent) :
        QWidget(parent), ui(new Ui::ScrabVision) {

    ui->setupUi(this);

    model = new ProcessListModel(this);

    ui->processListView->setModel(model);
}

ScrabVision::~ScrabVision() {
    delete ui;
}

void ScrabVision::onRefreshListButtonClicked()
{

}

