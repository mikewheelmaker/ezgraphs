import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Item {
    id: headerMainWindowContainer

    width: 10
    height: 10

    Rectangle {
        id: headerBackgroundRectangle

        anchors.fill: parent
        color: "#96DDF7"

        RowLayout {
            id: rowLayoutContainer

            anchors.fill: parent
            anchors.margins: 5

            ButtonTemplate {
                id: newCanvasButton

                buttonText: "New Canvas"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 100
                buttonFunction: 0
            }

            ButtonTemplate {
                id: importLaTeXFunctionsButton

                buttonText: "Import LaTeX Function(s)"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 150
                buttonFunction: 3
            }

            ButtonTemplate {
                id: exportLaTeXFunctionsButton

                buttonText: "Export LaTeX Function(s)"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 150
                buttonFunction: 4
            }

            ButtonTemplate {
                id: saveGraphButton

                buttonText: "Save As"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 50
                buttonFunction: 5
            }

            ButtonTemplate {
                id: syncButton

                buttonText: "Sync"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 50
                buttonFunction: 6
            }

            Rectangle {
                id: spacerRectangle

                Layout.fillHeight: true
                Layout.fillWidth: true
                color: parent.parent.color
            }

            ButtonTemplate {
                id: helpWindowButton

                buttonText: "Help"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 50
                buttonFunction: 7
            }

            ButtonTemplate {
                id: exitApplicationButton

                buttonText: "Exit"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 50
                buttonFunction: 8
            }
        }
    }
}
