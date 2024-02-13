import QtCore
import QtQuick

ListView {
    id: view
    width: parent.width
    height: parent.height
    model: ExpensesModel{}
    delegate: Rectangle {
        height: 15
        width: parent.width
        color: "white"
        Text {
            anchors.left: parent.left

            text: model.where
        }
        Text {
            anchors.right: parent.right

            text: model.size
        }
    }
}
