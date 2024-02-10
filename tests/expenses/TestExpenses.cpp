//
// Created by nyanbanan on 10.02.24.
//

#include <QTest>

#include "../../src/expenses/Expenses.hpp"

class TestExpenses : public QObject {
    Q_OBJECT
private slots:
    void testGetWhere_data();
    void testGetWhere();
    void testSetWhere_data();
    void testSetWhere();
};

QTEST_MAIN(TestExpenses)
#include "TestExpenses.moc"

void TestExpenses::testGetWhere_data() {
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("just_word") << "just_word"
                               << "just_word";
}

void TestExpenses::testGetWhere() {
    QFETCH(QString, string);
    QFETCH(QString, result);

    expenses::Expenses tst_expenses{string};

    QCOMPARE(tst_expenses.getWhere(), string);
}

void TestExpenses::testSetWhere_data() {
    QTest::addColumn<QString>("string");
    QTest::addColumn<QString>("result");

    QTest::newRow("just_word") << "just_word"
                               << "just_word";
}

void TestExpenses::testSetWhere() {
    QFETCH(QString, string);
    QFETCH(QString, result);

    expenses::Expenses tst_expenses;
    tst_expenses.setWhere(string);

    QCOMPARE(tst_expenses.getWhere(), result);
}
