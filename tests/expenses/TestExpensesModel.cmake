cmake_minimum_required(VERSION 3.27)

project(TestExpenses)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(TestExpensesModel ${CMAKE_CURRENT_LIST_DIR}/TestExpensesModel.cpp
         ${CMAKE_CURRENT_LIST_DIR}/../../src/expenses/ExpensesModel.cpp
         ${CMAKE_CURRENT_LIST_DIR}/../../src/expenses/Expenses.cpp)

add_test(NAME TestExpensesModel COMMAND TestExpensesModel)

target_link_libraries(TestExpensesModel PRIVATE Qt6::Test Qt6::Qml)

