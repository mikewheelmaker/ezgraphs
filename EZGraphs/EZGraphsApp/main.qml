import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml
import QtCharts

ApplicationWindow {
    id: mainWindow
    width: 1280
    height: 720
    visible: true
    title: "EZGraphs"

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

        function onFunctionListCleared() {
            functionGraph.functionChart.removeAllSeries();
        }
    }

    ColumnLayout {
        id: mainWindowContainer

        anchors.fill: parent
        spacing: 0

        HeaderMainWindow {
            id: header

            Layout.fillWidth: true
            Layout.preferredHeight: 50
        }

        FunctionInput {
            id: functionInput

            Layout.fillWidth: true
            Layout.preferredHeight: 50
        }

        Rectangle {
            id: contentBackgroundRectangle

            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#DFEFF5"

            RowLayout {
                id: contentContainer

                anchors.fill: parent
                spacing: 0

                Rectangle {
                    id: functionListBackgroundRectangle

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    color: "white"

                    ColumnLayout {
                        id: listContainer

                        anchors.fill: parent
                        anchors.margins: 5
                        spacing: 0

                        Rectangle {
                            id: listHeaderContainer

                            Layout.fillWidth: true
                            Layout.preferredHeight: 30

                            RowLayout {
                                id: listHeaderLayout

                                anchors.fill: parent

                                Text {
                                    Layout.preferredWidth: 100
                                    Layout.fillHeight: true
                                    text: "Alias"
                                    font.pixelSize: 15
                                }

                                Text {
                                    Layout.fillWidth: true
                                    Layout.fillHeight: true
                                    text: "Expression"
                                    font.pixelSize: 15
                                }

                                Text {
                                    Layout.preferredWidth: 50
                                    Layout.fillHeight: true
                                    text: "Step"
                                    font.pixelSize: 15
                                }

                                Text {
                                    Layout.preferredWidth: 60
                                    Layout.fillHeight: true
                                    text: "Remove"
                                    font.pixelSize: 15
                                }
                            }
                        }

                        ListView {
                            id: listViewContainer

                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            clip: true
                            spacing: 5

                            model: ApplicationManager.functionModel
                            delegate: ListViewDelegate {}
                        }
                    }
                }

                Rectangle {
                    id: dividerRectangle

                    Layout.preferredWidth: 3
                    Layout.fillHeight: true
                    color: "black"
                }

                Rectangle {
                    id: graphBackgroundRectangle

                    Layout.fillWidth: true
                    Layout.fillHeight: true
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
