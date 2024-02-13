//
// Created by nyanbanan on 10.02.24.
//

#include <QTest>

#include "../../src/expenses/Expenses.hpp"

class TestExpenses : public QObject {
    Q_OBJECT
private slots:
    void testGetSetWhere();
    void testGetSetSize();
    void testGetSetDate();
};

QTEST_MAIN(TestExpenses)
#include "TestExpenses.moc"

void TestExpenses::testGetSetWhere() {
    QString name{"test_name"};

    expenses::Expenses tst_expenses;
    tst_expenses.setWhere(name);

    QCOMPARE(tst_expenses.getWhere(), name);

    expenses::Expenses tst_expenses1{name};

    QCOMPARE(tst_expenses1.getWhere(), name);
}

void TestExpenses::testGetSetSize() {
    quint64 size{1000};

    expenses::Expenses tst_expenses;
    tst_expenses.setSize(size);

    QCOMPARE(tst_expenses.getSize(), size);

    expenses::Expenses tst_expenses1{"", size};

    QCOMPARE(tst_expenses1.getSize(), size);
}

void TestExpenses::testGetSetDate() {
    QDateTime date{};

    expenses::Expenses tst_expenses;
    tst_expenses.setDate(date);

    QCOMPARE(tst_expenses.getDate(), date);

    expenses::Expenses tst_expenses1{"", 0, date};

    QCOMPARE(tst_expenses1.getDate(), date);
}
