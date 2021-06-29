import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml
import QtCharts

ApplicationWindow {
    width: 1280
    height: 720
    visible: true

    Connections {
        target: ApplicationManager

        function onFunctionAdded(alias, expression, color, numberOfValues) {
            var newSeries = functionGraph.functionChart.createSeries(ChartView.SeriesTypeLine, alias, functionGraph.axisX, functionGraph.axisY);
            newSeries.color = color;
            var tempList = ApplicationManager.currentFunctionValues;
            for(var i=0; i < numberOfValues; ++i)
                newSeries.append(tempList[i].x, tempList[i].y);
        }

        function onFunctionRemoved(index) {
            functionGraph.functionChart.removeSeries(functionGraph.functionChart.series(index))
        }

        function onListCleared() {
            functionGraph.functionChart.removeAllSeries();
        }
    }

    title: qsTr("EZGraphs")

    ColumnLayout {
        id: mainWindowContainer

        anchors.fill: parent
        spacing: 0

        HeaderMainWindow {
            id: header

            Layout.preferredHeight: 50
            Layout.fillWidth: true
        }

        FunctionInput {
            id: functionInput

            Layout.preferredHeight: 50
            Layout.fillWidth: true
        }

        Rectangle {
            id: contentBackgroundRectangle

            Layout.fillHeight: true
            Layout.fillWidth: true
            color: "#DFEFF5"

            RowLayout {
                id: contentContainer

                anchors.fill: parent
                spacing: 0

                Rectangle {
                    id: functionListBackgroundRectangle

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "white"

                    ListView {
                        id: listViewContainer

                        anchors.fill: parent
                        anchors.margins: 10
                        clip: true
                        spacing: 10

                        model: ApplicationManager.functionModel
                        delegate: ListViewDelegate {}
                    }
                }

                Rectangle {
                    id: dividerRectangle

                    Layout.fillHeight: true
                    Layout.preferredWidth: 3
                    color: "black"
                }

                Rectangle {
                    id: graphBackgroundRectangle

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "white"

                    FunctionGraph {
                        id: functionGraph

                        anchors.fill: parent

                        chartTitle: "Function Graphs"
                        minX: -10
                        minY: -10
                        maxX: 10
                        maxY: 10
                    }
                }
            }
        }
    }
}
