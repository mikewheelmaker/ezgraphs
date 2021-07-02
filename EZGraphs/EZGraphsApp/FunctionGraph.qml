import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml
import QtCharts

Item {
    id: functionGraphContainer

    width: 10
    height: 10

    property string chartTitle: ""
    property double minX: 0
    property double minY: 0
    property double maxX: 0
    property double maxY: 0

    property alias functionChart: functionChartView
    property alias axisX: axisX
    property alias axisY: axisY

    ChartView {
        id: functionChartView
        title: chartTitle
        anchors.fill: parent

        ValuesAxis {
            id: axisX

            min: minX
            max: maxX
        }

        ValueAxis {
            id: axisY

            min: minY
            max: maxY
        }
    }
}
