import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Qt.labs.platform
import expenses

ApplicationWindow {
    readonly property alias pages: pages
    readonly property alias view: view

    visible: true

    SwipeView {
        id: view

        anchors.fill: parent
        wheelEnabled: true

        Repeater{
            model: pages
            delegate: Loader{
                source: model.page
            }
        }
    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ListModel {
        id: pages
        ListElement {
            index: 0
            name: qsTr("PieChart");
            page: qsTr("/expenses/ExpensesPieChart.qml")
        }
        ListElement {
            index: 1
            name: qsTr("ListView");
            page: qsTr("/expenses/ExpensesList.qml")
        }
        ListElement {
            index: 2
            name: qsTr("Account");
        }
    }
}