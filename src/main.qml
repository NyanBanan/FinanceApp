import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Qt.labs.platform
import expenses

ApplicationWindow {
    id: root
    visible: true
    minimumWidth: 300
    minimumHeight: 400

    ExpensesPieChart{}
}