import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Dialog {
    id: confirmRemoveFunctionDialog

    title: "Remove function"
    width: 200
    height: 120
    anchors.centerIn: Overlay.overlay

    ColumnLayout {
        id: dialogWindowContainer

        anchors.fill: parent

        Text {
            id: confirmationText
            text: "Are you sure?"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 15

            Layout.fillWidth: true
            Layout.preferredHeight: 40
        }

        RowLayout {
            id: optionsContainer

            Layout.fillWidth: true
            Layout.fillHeight: true

            Button {
                id: dialogAcceptButton

                text: "Yes"
                font.pixelSize: 15
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    ApplicationManager.removeFunction()
                    confirmRemoveFunctionDialog.close()
                }
            }

            Button {
                id: dialogCancelButton

                text: "No"
                font.pixelSize: 15
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: confirmRemoveFunctionDialog.close()
            }
        }
    }
}
