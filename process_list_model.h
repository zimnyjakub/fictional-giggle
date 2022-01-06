//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_PROCESS_LIST_MODEL_H
#define SCRABVISION_PROCESS_LIST_MODEL_H


#include <QAbstractListModel>
#include "pidname.h"

class ProcessListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ProcessListModel(QObject *parent = nullptr);
    ProcessListModel(QVector<QPair<int,QString>> pairs, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;

    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool removeRows(int row, int count, const QModelIndex &parent) override;

    bool insertRows(int row, int count, const QModelIndex &parent) override;

private:
    QVector<QPair<int, QString>> processes;
};


#endif //SCRABVISION_PROCESS_LIST_MODEL_H
