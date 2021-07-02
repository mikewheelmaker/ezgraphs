import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Item {
    id: headerMainWindowContainer

    width: 10
    height: 10

    SaveAsDialog {
        id: saveAsDialog
    }

    Rectangle {
        id: headerBackgroundRectangle

        anchors.fill: parent
        color: "#96DDF7"

        RowLayout {
            id: rowLayoutContainer

            anchors.fill: parent
            anchors.margins: 5

            Button {
                id: clearGraphButton

                text: "Clear Graph"
                font.pixelSize: 15
                Layout.preferredWidth: 100
                Layout.preferredHeight: 30
                onClicked: ApplicationManager.clearGraph()
            }

            Button {
                id: saveGraphButton

                text: "Save As"
                font.pixelSize: 15
                Layout.preferredWidth: 80
                Layout.preferredHeight: 30
                onClicked: saveAsDialog.open()
            }

            Rectangle {
                id: spacerRectangle

                Layout.fillWidth: true
                Layout.fillHeight: true
                color: parent.parent.color
            }

            Button {
                id: helpWindowButton

                text: "Help"
                font.pixelSize: 15
                Layout.preferredWidth: 50
                Layout.preferredHeight: 30
                onClicked: ApplicationManager.openHelp()
            }

            Button {
                id: exitApplicationButton

                text: "Exit"
                font.pixelSize: 15
                Layout.preferredWidth: 50
                Layout.preferredHeight: 30
                onClicked: close()
            }
        }
    }
}
