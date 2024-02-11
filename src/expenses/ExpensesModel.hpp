//
// Created by nyanbanan on 10.02.24.
//

#ifndef FINANCEAPP_EXPENSESMODEL_HPP
#define FINANCEAPP_EXPENSESMODEL_HPP

#include <QAbstractItemModel>

#include "Expenses.hpp"

namespace expenses {

    class ExpensesModel : public QAbstractListModel {
    public:
        enum Roles {
            FirstRole = Qt::UserRole + 1,    //Don't use this role. This role uses only for column counting
                                             //If you need new role, place them after this role
            WhereRole,
            SizeRole,

            LastRole    //Don't use this role. This role uses only for column counting
                        //If you need new role, place them before this role
        };

        ExpensesModel() = default;

        [[nodiscard]] int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        [[nodiscard]] QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

        void insertRow(int row, const Expenses& expenses);
        void insertRows(int row, int count, QList<Expenses> expenses);

    private:
        [[nodiscard]] bool hasData(int row) const;

        QList<Expenses> _expenses;
    };

}    //namespace expenses
#endif    //FINANCEAPP_EXPENSESMODEL_HPP
