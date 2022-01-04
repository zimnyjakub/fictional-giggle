//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_PROCESS_LIST_MODEL_H
#define SCRABVISION_PROCESS_LIST_MODEL_H


#include <QAbstractListModel>

class ProcessListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ProcessListModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

};


#endif //SCRABVISION_PROCESS_LIST_MODEL_H
