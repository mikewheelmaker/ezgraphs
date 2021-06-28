import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Item {
    id: functionInputContainer

    width: 10
    height: 10

    Rectangle {
        id: functionInputBackgroundRectangle

        anchors.fill: parent
        color: "blue"

        RowLayout {
            id: rowLayoutContainer
            anchors.fill: parent
            anchors.margins: 5

            TextField {
                id: functionFormulaInput

                Layout.preferredHeight: 30
                Layout.fillWidth: true

                placeholderText: "Enter formula here"
                verticalAlignment: Qt.AlignVCenter
            }

            ButtonTemplate {
                id: addFunctionButton

                buttonText: "Add Function"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 100
                buttonFunction: 1
            }
        }
    }
}
