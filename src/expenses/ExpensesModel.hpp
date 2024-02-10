//
// Created by nyanbanan on 10.02.24.
//

#ifndef FINANCEAPP_EXPENSESMODEL_HPP
#define FINANCEAPP_EXPENSESMODEL_HPP

#include <QAbstractItemModel>

#include "Expenses.hpp"

namespace expenses {

    enum ExpensesRoles{
        WhereRole = Qt::UserRole + 1,
        SizeRole
    };

    class ExpensesModel : public QAbstractItemModel{
    public:
        ExpensesModel() = default;

        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
//        QModelIndex parent(const QModelIndex &child) const override;
//        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
//        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        bool hasIndex(int row, int column) const;

    private:
        QList<Expenses> _expenses;
    };

}
#endif    //FINANCEAPP_EXPENSESMODEL_HPP
