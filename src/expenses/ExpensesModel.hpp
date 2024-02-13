//
// Created by nyanbanan on 10.02.24.
//

#ifndef FINANCEAPP_EXPENSESMODEL_HPP
#define FINANCEAPP_EXPENSESMODEL_HPP

#include <QAbstractListModel>
#include <QtQml>

#include "Expenses.hpp"

namespace expenses {

    class ExpensesModel : public QAbstractItemModel {
        Q_OBJECT
        QML_ELEMENT
    public:
        enum Roles {
            FirstRole = Qt::UserRole + 1,    //Don't use this role. This role uses only for column counting
                                             //If you need new role, place them after this role
            WhereRole,
            SizeRole,

            LastRole    //Don't use this role. This role uses only for column counting
                        //If you need new role, place them before this role
        };

        [[nodiscard]] QModelIndex parent(const QModelIndex &child) const override;
        [[nodiscard]] QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
        [[nodiscard]] int rowCount(const QModelIndex& parent = QModelIndex()) const override;
        [[nodiscard]] int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        [[nodiscard]] QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
        [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    public slots:
        void insertRow(int row, const expenses::Expenses& expenses);
        void insertRows(int row, int count, QList<expenses::Expenses> expenses);

    private:
        [[nodiscard]] bool hasIndex(int row, int column) const;

        QList<Expenses> _expenses{{"deleteOnReleaseAndChangeTest", 2100}};
    };

}    //namespace expenses
#endif    //FINANCEAPP_EXPENSESMODEL_HPP
