//
// Created by nyanbanan on 10.02.24.
//

#include "ExpensesModel.hpp"

namespace expenses {

    bool ExpensesModel::hasData(int row) const {
        return row < rowCount() && row >= 0;
    }

    int ExpensesModel::rowCount(const QModelIndex& parent) const {
        return int(_expenses.count());
    }

    QVariant ExpensesModel::data(const QModelIndex& index, int role) const {
        if (!hasData(index.row())) {
            return {};
        }
        switch (role) {
            case Qt::DisplayRole: {
                return QVariant::fromValue(_expenses[index.row()].toString());
            }
            case WhereRole: {
                return QVariant::fromValue(_expenses[index.row()].getWhere());
            }
            case SizeRole: {
                return QVariant::fromValue(_expenses[index.row()].getSize());
            }
            default:
                return {};
        }
    }

    void ExpensesModel::insertRow(int row, const Expenses& expenses) {
        beginInsertRows({}, row, row);
        _expenses.insert(row, expenses);
        endInsertRows();
    }

    void ExpensesModel::insertRows(int row, int count, QList<Expenses> expenses) {
        beginInsertRows({}, row, row + count);
        for (const auto& item : expenses) {
            _expenses.insert(row++, item);
        }
        endInsertRows();
    }

}    //namespace expenses
