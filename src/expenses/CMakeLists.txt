
qt_add_qml_module(expenses
        URI expenses
        VERSION 1.0
        RESOURCE_PREFIX /
        SOURCES
            Expenses.cpp
            Expenses.hpp
            ExpensesModel.cpp
            ExpensesModel.hpp
        QML_FILES
            ExpensesPieChart.qml
)