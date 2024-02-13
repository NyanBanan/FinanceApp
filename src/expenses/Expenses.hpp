//
// Created by nyanbanan on 10.02.24.
//

#ifndef FINANCEAPP_EXPENSES_HPP
#define FINANCEAPP_EXPENSES_HPP

#include <QDateTime>
#include <QObject>
#include <QString>

namespace expenses {

    class Expenses{
    public:
        Expenses() = default;
        explicit Expenses(QString where);
        Expenses(QString where, quint64 size);
        Expenses(QString where, quint64 size, QDateTime date);

        [[nodiscard]] const QString& getWhere() const;
        void setWhere(QString where);

        [[nodiscard]] quint64 getSize() const;
        void setSize(quint64 size);

        [[nodiscard]] const QDateTime& getDate() const;
        void setDate(const QDateTime& date);

        [[nodiscard]] QString toString() const;

    private:
        QString _where;
        quint64 _size{0};
        QDateTime _date{};
    };

}    //namespace expenses

#endif    //FINANCEAPP_EXPENSES_HPP
