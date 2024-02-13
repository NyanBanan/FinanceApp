add_subdirectory(expenses)

qt_add_executable(FinanceApp main.cpp)

qt_add_qml_module(FinanceApp
        VERSION 1.0
        URI FinanceAppQml
        RESOURCE_PREFIX /
        QML_FILES
        main.qml
        FinanceAppMainWindow.qml
        +android/main.qml
)

target_link_libraries(FinanceApp PRIVATE expenses Qt6::Core Qt6::Widgets Qt6::Gui Qt6::Quick Qt6::Qml)

if (ANDROID)
    set_target_properties(FinanceApp PROPERTIES
            QT_ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../android"
    )
    qt_add_resources(FinanceApp "images"
            PREFIX "/"
            FILES ../resources/menu.ico
    )
endif ()