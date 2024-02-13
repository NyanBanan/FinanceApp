cmake_minimum_required(VERSION 3.27)

project(TestExpenses)

find_package(Qt6 REQUIRED COMPONENTS Core Test)

add_executable(TestExpenses ${CMAKE_CURRENT_LIST_DIR}/TestExpenses.cpp
        ${CMAKE_CURRENT_LIST_DIR}/../../src/expenses/Expenses.cpp)

add_test(NAME TestExpenses COMMAND TestExpenses)

target_link_libraries(TestExpenses PRIVATE Qt6::Core Qt6::Test Qt6::Qml)

