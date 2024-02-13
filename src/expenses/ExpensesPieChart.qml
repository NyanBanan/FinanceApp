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
    VPieModelMapper {
        id: mapper
        series: pieSeries
        model: ExpensesModel{}
        labelsColumn: 0
        valuesColumn: 1
    }
}
