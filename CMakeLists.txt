cmake_minimum_required(VERSION 3.27)

project(FinanceApp)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing(true)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick Qml)

qt_add_executable(FinanceApp src/main.cpp)

add_subdirectory(tests)

target_link_libraries(FinanceApp PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui Qt6::Quick Qt6::Qml)


