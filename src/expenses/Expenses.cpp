//
// Created by nyanbanan on 10.02.24.
//

#include "Expenses.hpp"

namespace expenses {

    Expenses::Expenses(QString where) : _where(where) {}

    Expenses::Expenses(QString where, quint64 size) : _where(where), _size(size) {}

    Expenses::Expenses(QString where, quint64 size, QDateTime date): _where(where), _size(size), _date(date) {}

    const QString& Expenses::getWhere() const {
        return _where;
    }

    void Expenses::setWhere(QString where) {
        _where = std::forward<QString>(where);
    }

    quint64 Expenses::getSize() const {
        return _size;
    }

    void Expenses::setSize(quint64 size) {
        _size = size;
    }

    const QDateTime& Expenses::getDate() const {
        return _date;
    }

    void Expenses::setDate(const QDateTime& date) {
        _date = date;
    }

    QString Expenses::toString() const {
        return QString("%1 %2 %3").arg(getWhere()).arg(getSize()).arg(getDate().toString());
    }
}    //namespace expenses
