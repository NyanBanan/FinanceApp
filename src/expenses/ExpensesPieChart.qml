import QtCore
import QtCharts

ChartView {
    readonly property alias model: mapper.model

    id: chart
    width: parent.width
    height: parent.height
    PieSeries {
        id: pieSeries
    }
    ExpensesModel {
        id: expensesModel
    }
    VPieModelMapper {
        id: mapper
        series: pieSeries
        model: expensesModel
        labelsColumn: 0
        valuesColumn: 1
    }
}
