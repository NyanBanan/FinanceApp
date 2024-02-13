import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

FinanceAppMainWindow {
    id: root
    menuBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                Layout.alignment: Qt.AlignLeft

                icon.color: "transparent"
                icon.source: "qrc:/resources/menu.ico"
                onClicked: function () {
                    drawer.open()
                }
            }
        }
    }
    Drawer {
        id: drawer
        width: 0.6 * Math.min(parent.width, parent.height)
        height: parent.height

        ListView {
            id: buttonList
            anchors.fill: parent
            focus: true
            currentIndex: view.currentIndex

            delegate: ItemDelegate {
                text: model.name
                width: drawer.width

                highlighted: ListView.isCurrentItem
                onClicked: {
                    view.setCurrentIndex(model.index)
                }
            }
            model: pages
        }
    }

    Binding {
        root.view.currentIndex: buttonList.currentIndex
    }
}