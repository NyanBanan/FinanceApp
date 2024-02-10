//
// Created by nyanbanan on 10.02.24.
//

#include <QTest>

#include "../../src/expenses/ExpensesModel.hpp"

class TestExpensesModel : public QObject {
    Q_OBJECT
private slots:
    void testIndex();
};

QTEST_MAIN(TestExpensesModel)
#include "TestExpensesModel.moc"

void TestExpensesModel::testIndex() {
}