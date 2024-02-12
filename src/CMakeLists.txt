add_subdirectory(expenses)

qt_add_executable(FinanceApp main.cpp)

qt_add_qml_module(FinanceApp
        VERSION 1.0
        URI FinanceAppQml
        RESOURCE_PREFIX /
        QML_FILES
        main.qml
)

target_link_libraries(FinanceApp PRIVATE expenses Qt6::Core Qt6::Widgets Qt6::Gui Qt6::Quick Qt6::Qml)