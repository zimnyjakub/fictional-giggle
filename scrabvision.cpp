//
// Created by zimny on 04.01.2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScrabVision.h" resolved

#include "scrabvision.h"
#include "ui_scrabvision.h"


ScrabVision::ScrabVision(QWidget *parent) :
        QWidget(parent), ui(new Ui::ScrabVision) {
    ui->setupUi(this);
}

ScrabVision::~ScrabVision() {
    delete ui;
}

