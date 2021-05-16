import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

ApplicationWindow {
    width: 1280
    height: 720
    visible: true
    //visibility: Qt.WindowFullScreen

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
                    color: "#000000"
                }

                Rectangle {
                    id: graphBackgroundRectangle

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "#FFFFFF"
                }
            }
        }
    }
}
