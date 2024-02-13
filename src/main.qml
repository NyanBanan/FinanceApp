import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQml

import Qt.labs.platform

FinanceAppMainWindow {
    id: root

    header: Row {
        TabBar {
            id: bar
            wheelEnabled: true
            width: root.width
            currentIndex: view.currentIndex

            Repeater {
                delegate: TabButton {
                    text: model.name
                    width: bar.width / 4
                }
                model: pages
            }
        }
    }

    Binding{
        root.view.currentIndex: bar.currentIndex
    }
}