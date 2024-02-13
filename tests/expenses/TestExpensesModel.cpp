//
// Created by nyanbanan on 10.02.24.
//

#include <QTest>

#include "../../src/expenses/ExpensesModel.hpp"

class TestExpensesModel : public QObject {
    Q_OBJECT
private slots:
    void testRowCount();
    void testData();
    void testInsert();
};

QTEST_MAIN(TestExpensesModel)
#include "TestExpensesModel.moc"

void TestExpensesModel::testInsert() {
    expenses::ExpensesModel model;
    expenses::Expenses expenses{"Test", 1000};

    model.insertRow(0, expenses);

    QCOMPARE(model.data(model.index(0,0)), expenses.getWhere());
    QCOMPARE(model.data(model.index(0,1)), expenses.getSize());
}

void TestExpensesModel::testData() {
    expenses::ExpensesModel model;
    expenses::Expenses expenses{"Test", 1000};

    model.insertRow(0, expenses);

    QCOMPARE(model.data(model.index(0, 0), expenses::ExpensesModel::Roles::WhereRole), expenses.getWhere());
    QCOMPARE(model.data(model.index(0, 1), expenses::ExpensesModel::Roles::SizeRole), expenses.getSize());
}

void TestExpensesModel::testRowCount() {
    expenses::ExpensesModel model;

    QCOMPARE(model.rowCount(), 1);

    expenses::Expenses expenses{"Test", 1000};

    model.insertRow(0, expenses);

    QCOMPARE(model.rowCount(), 2);
}
