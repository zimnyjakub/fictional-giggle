//
// Created by zimny on 04.01.2022.
//

#include "process_list_model.h"

QVariant ProcessListModel::data(const QModelIndex &index, int role) const {
    qDebug() << QString("row %1, col%2, role %3");
    if (role == Qt::DisplayRole)
        return QString("Row%1, Column%2")
                .arg(index.row() + 1)
                .arg(index.column() +1);

    return {};

}

int ProcessListModel::rowCount(const QModelIndex &parent) const {
    return 3;
}

ProcessListModel::ProcessListModel(QObject *parent) : QAbstractListModel(parent) {

}
