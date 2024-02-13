import QtCore
import QtQuick

ListView {
    id: view
    width: parent.width
    height: parent.height
    model: ExpensesModel {
    }
    delegate: Rectangle {
        height: 50
        width: parent.width
        color: "white"

        Text {
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignLeft

            width: parent.width / 3

            text: model.where
        }
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: textVerticalAlignment

            width: parent.width / 3

            text: model.date.toLocaleString(Qt.locale(), "hh:mm dd.MM.yyyy")
        }
        Text {
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            horizontalAlignment: Text.AlignRight
            verticalAlignment: textVerticalAlignment

            width: parent.width / 3

            text: model.size
        }
    }
}
