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

    on_debugButton_clicked();
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

        model->setData(ix, window.pid, Qt::EditRole);
        ix = model->index(0, 1);
        model->setData(ix, window.name, Qt::EditRole);
        ix = model->index(0, 2);
        model->setData(ix, QVariant::fromValue(window.hwnd), Qt::EditRole);
    }
}

void ScrabVision::on_useSelectedButton_clicked() {
    auto selection = ui->tableView->selectionModel();
    if (!selection->hasSelection()) {
        return;
    }
    auto items = selection->selectedRows().first();
    if (items.isValid()) {
        auto pid = model->data(model->index(items.row(), 0), Qt::DisplayRole).toInt();
        selectedPid = pid;
        ui->currentPidLabel->setText(QString::number(pid));
        auto h = model->data(model->index(items.row(), 2), Qt::DisplayRole).value<HWND>();
        selectedHwnd = h;
    }
}


void ScrabVision::on_debugButton_clicked() {
    qDebug() << selectedHwnd;
//    originalCapture = captureScreenMat(selectedHwnd);
    originalCapture = cv::imread("800x600.png", cv::IMREAD_COLOR);
    if (!originalCapture.data) {

        qDebug() << "No image data \n";
        return;
    }
    auto scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    cvtColor(originalCapture, originalCapture, COLOR_BGRA2RGBA);


    QImage qImg(originalCapture.data, originalCapture.cols, originalCapture.rows, originalCapture.step, QImage::Format_RGBA8888_Premultiplied);
    auto pixImg = QPixmap::fromImage(qImg);
    scene->addPixmap(pixImg);
}

#endif //SCRABVISION_SCRABVSION_CPP
