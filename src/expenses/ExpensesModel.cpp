//
// Created by nyanbanan on 10.02.24.
//

#include "ExpensesModel.hpp"

namespace expenses {

    QModelIndex ExpensesModel::index(int row, int column, const QModelIndex& parent) const {
        if(hasIndex(row, column)){
            switch (column) {
                case ExpensesRoles::WhereRole:{
                    return createIndex(row, column, &_expenses[row].getWhere());
                }
                case ExpensesRoles::SizeRole:{
                    return createIndex(row, column, _expenses[row].getSize());
                }
                default:
                    QModelIndex{};
            }
        }
        return {};
    }

    bool ExpensesModel::hasIndex(int row, int column) const {
        return row < rowCount() && row >= 0 && column < columnCount() && column >= 0;
    }
}