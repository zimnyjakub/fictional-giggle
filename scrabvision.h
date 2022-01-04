//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_SCRABVISION_H
#define SCRABVISION_SCRABVISION_H

#include "process_list_model.h"

#include <QWidget>
#include <QStringListModel>


QT_BEGIN_NAMESPACE
namespace Ui { class ScrabVision; }
QT_END_NAMESPACE

class ScrabVision : public QWidget {
Q_OBJECT

public:
    explicit ScrabVision(QWidget *parent = nullptr);

    ProcessListModel *model;

    ~ScrabVision() override;

private slots:
    void onRefreshListButtonClicked();

private:
    Ui::ScrabVision *ui;
};


#endif //SCRABVISION_SCRABVISION_H
