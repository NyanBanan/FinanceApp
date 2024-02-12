cmake_minimum_required(VERSION 3.27)

project(FinanceApp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing(true)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick Qml)

add_subdirectory(tests)
add_subdirectory(src)