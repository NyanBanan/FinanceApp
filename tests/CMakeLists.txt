cmake_minimum_required(VERSION 3.27)

project(FinanceAppTests)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick Qml)

include(expenses/TestExpenses.cmake)
include(expenses/TestExpensesModel.cmake)
