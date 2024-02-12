cmake_minimum_required(VERSION 3.27)

project(TestExpenses)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(TestExpensesModel ${CMAKE_CURRENT_LIST_DIR}/TestExpensesModel.cpp
        ../../src/expenses/ExpensesModel.cpp
        ../../src/expenses/Expenses.cpp)

add_test(NAME TestExpensesModel COMMAND TestExpensesModel)

target_link_libraries(TestExpensesModel PRIVATE Qt6::Test Qt6::Qml)

