//
// Created by zimny on 04.01.2022.
//

#ifndef SCRABVISION_PROCESS_LIST_MODEL_CPP
#define SCRABVISION_PROCESS_LIST_MODEL_CPP

#include "process_list_model.h"

#include <utility>

QVariant ProcessListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return {};

    if (index.row() >= processes.size() || index.row() < 0)
        return {};

    if (role == Qt::DisplayRole) {
        ProcessModel p = processes.at(index.row());

        if (index.column() == 0)
            return p.pid;
        else if (index.column() == 1)
            return p.name;
        else if (index.column() == 2)
            return QVariant::fromValue(p.hwnd);
    }
    return {};

}

int ProcessListModel::rowCount(const QModelIndex &parent) const {
    return processes.size();
}

ProcessListModel::ProcessListModel(QObject *parent) : QAbstractTableModel(parent) {
}

int ProcessListModel::columnCount(const QModelIndex &parent) const {
    return 3;
}

QVariant ProcessListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return {};

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("PID");

            case 1:
                return tr("Name");

            default:
                return {};
        }
    }
    return {};
}

bool ProcessListModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        auto p = processes.at(row);

        if (index.column() == 0) { p.pid = value.toInt(); }
        else if (index.column() == 1) { p.name = value.toString(); }
        else if (index.column() == 2) {
            auto h = qvariant_cast<HWND>(value);
            p.hwnd = h;
        } else
            return false;


        processes.replace(row, p);
        emit(dataChanged(index, index));

        return true;
    }

    return false;
}

Qt::ItemFlags ProcessListModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index);
}

ProcessListModel::ProcessListModel(QVector <ProcessModel> m, QObject *parent) : QAbstractTableModel(parent) {
    processes = std::move(m);
}

bool ProcessListModel::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; i++) {
        ProcessModel p{nullptr, 0, "TODOME"};
        processes.insert(i, p);
    }

    endInsertRows();
    return true;
}

bool ProcessListModel::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; row < count; ++row) {
        processes.removeAt(i);
    }

    endRemoveRows();
    return true;
}

#endif //SCRABVISION_PROCESS_LIST_MODEL_CPP
