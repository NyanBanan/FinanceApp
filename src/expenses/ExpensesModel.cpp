//
// Created by nyanbanan on 10.02.24.
//

#include "ExpensesModel.hpp"

namespace expenses {

    QModelIndex ExpensesModel::parent(const QModelIndex& child) const {
        Q_UNUSED(child)
        return {};
    }

    QModelIndex ExpensesModel::index(int row, int column, const QModelIndex& parent) const {
        Q_UNUSED(parent)
        if (!hasIndex(row, column)) {
            return {};
        }
        return createIndex(row, column);
    }

    bool ExpensesModel::hasIndex(int row, int column) const {
        return row < rowCount() && row >= 0 && column < columnCount() && column >= 0;
    }

    int ExpensesModel::rowCount(const QModelIndex& parent) const {
        Q_UNUSED(parent)
        return int(_expenses.count());
    }

    int ExpensesModel::columnCount(const QModelIndex& parent) const {
        Q_UNUSED(parent)
        return LastRole - FirstRole - 1;
    }

    QVariant ExpensesModel::data(const QModelIndex& index, int role) const {
        switch (role) {
            case Qt::DisplayRole: {
                switch (index.column()) {
                    case WhereRole - FirstRole - 1: {
                        return QVariant::fromValue(_expenses[index.row()].getWhere());
                    }
                    case SizeRole - FirstRole - 1: {
                        return QVariant::fromValue(_expenses[index.row()].getSize());
                    }
                    case DateRole - FirstRole - 1: {
                        return QVariant::fromValue(_expenses[index.row()].getDate());
                    }
                    default:
                        return {};
                }
            }
            case WhereRole: {
                return QVariant::fromValue(_expenses[index.row()].getWhere());
            }
            case SizeRole: {
                return QVariant::fromValue(_expenses[index.row()].getSize());
            }
            case DateRole: {
                return QVariant::fromValue(_expenses[index.row()].getDate());
            }
            default:
                return {};
        }
    }

    QHash<int, QByteArray> ExpensesModel::roleNames() const {
        QHash<int, QByteArray> roles = QAbstractItemModel::roleNames();

        roles[WhereRole] = "where";
        roles[SizeRole] = "size";

        return roles;
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
