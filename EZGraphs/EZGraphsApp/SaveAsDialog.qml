import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Dialog {
    id: saveAsOptionsDialog

    title: "Save As"
    width: 250
    height: 100
    anchors.centerIn: Overlay.overlay

    ColumnLayout {
        id: mainContainer

        anchors.fill: parent

        RowLayout {
            id: optionsContainer

            Layout.fillWidth: true
            Layout.fillHeight: true

            ComboBox {
                id: fileFormatOption

                Layout.preferredWidth: 45
                Layout.preferredHeight: 30

                currentIndex: 0
                model: [ "PNG", "BMP", "JPG", "PDF" ]
            }

            TextField {
                id: fileName

                Layout.fillWidth: true
                Layout.preferredHeight: 30

                placeholderText: "Enter file name here"
                verticalAlignment: Qt.AlignVCenter
            }
        }

        RowLayout {
            id: buttonsContainer

            Layout.fillWidth: true
            Layout.fillHeight: true

            Button {
                id: saveButton

                text: "Save"
                font.pixelSize: 15
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: {
                    if(fileName.text.length != 0)
                    {
                        ApplicationManager.saveGraph(fileFormatOption.currentIndex, fileName.text)
                        saveAsOptionsDialog.close()
                    }
                    fileName.placeholderText = "MANDATORY"
                    fileName.placeholderTextColor = "red"
                }
            }

            Button {
                id: cancelButton

                text: "Cancel"
                font.pixelSize: 15
                Layout.alignment: Qt.AlignCenter
                Layout.fillWidth: true
                Layout.fillHeight: true
                onClicked: saveAsOptionsDialog.close()
            }
        }
    }
}
