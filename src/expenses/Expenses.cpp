//
// Created by nyanbanan on 10.02.24.
//

#include "Expenses.hpp"

namespace expenses {

    Expenses::Expenses(QString where) : _where(where) {}

    Expenses::Expenses(QString where, quint64 size) : _where(where), _size(size) {}

    const QString& Expenses::getWhere() const {
        return _where;
    }

    void Expenses::setWhere(QString where) {
        _where = where;
    }

    quint64 Expenses::getSize() const {
        return _size;
    }

    void Expenses::setSize(quint64 size) {
        _size = size;
    }
}    //namespace expenses
