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
        id: backgroundRectangle

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
                buttonFunction: 1
            }

            ButtonTemplate {
                id: exportLaTeXFunctionsButton

                buttonText: "Export LaTeX Function(s)"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 150
                buttonFunction: 2
            }

            ButtonTemplate {
                id: saveGraphButton

                buttonText: "Save"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 50
                buttonFunction: 3
            }

            Rectangle {
                id: spacerRectangle

                Layout.fillHeight: true
                Layout.fillWidth: true
                color: parent.parent.color
            }

            ButtonTemplate {
                id: exitApplicationButton

                buttonText: "Exit"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 50
                buttonFunction: 4
                Layout.alignment: Qt.AlignRight
            }
        }
    }
}
