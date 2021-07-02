import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Window {
    id: functionInfoWindow

    property string functionAlias: ""
    property alias injectivePropertyText: injectiveProperty.text
    property alias surjectivePropertyText: surjectiveProperty.text

    width: 200
    height: 100
    visible: true
    title: functionAlias + " details"

    ColumnLayout {
        id: mainContainer

        anchors.fill: parent
        anchors.margins: 10

        Rectangle {
            id: headerContainer

            Layout.fillWidth: true
            Layout.preferredHeight: 30

            RowLayout {
                anchors.fill: parent
                spacing: 0

                Text {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    horizontalAlignment: Qt.AlignHCenter
                    text: "Is Injective?"
                    font.pixelSize: 15
                }

                Text {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    horizontalAlignment: Qt.AlignHCenter
                    text: "Is Surjective?"
                    font.pixelSize: 15
                }
            }
        }

        Rectangle {
            id: detailsContainer

            Layout.fillWidth: true
            Layout.fillHeight: true

            RowLayout {
                anchors.fill: parent
                spacing: 0

                Text {
                    id: injectiveProperty

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    horizontalAlignment: Qt.AlignHCenter
                    text: ""
                    font.pixelSize: 15
                }

                Text {
                    id: surjectiveProperty

                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    horizontalAlignment: Qt.AlignHCenter
                    text: ""
                    font.pixelSize: 15
                }
            }
        }
    }
}
