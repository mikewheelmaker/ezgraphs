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
    //visibility: Qt.WindowFullScreen

    Connections {
        target: ApplicationManager
        function onValueAdded() {
            functionGraph.functionValues.append(ApplicationManager.value.x, ApplicationManager.value.y);
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

                        chartTitle: "New Title"
                        lineColor: "black"
                        minX: 0
                        minY: -1.1
                        maxX: 10
                        maxY: 1.1
                    }
                }
            }
        }
    }
}
