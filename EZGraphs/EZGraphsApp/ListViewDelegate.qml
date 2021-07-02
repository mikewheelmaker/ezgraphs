import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Item {
    id: itemContainer

    width: listViewContainer.width
    height: 20

    RemoveFunctionDialog {
        id: functionRemoveDialog
    }

    MouseArea {
        id: mouseAreaDelegate

        anchors.fill: parent

        onDoubleClicked: {
            var component = Qt.createComponent("InfoWindow.qml");

            var window = component.createObject(mainWindow);
            window.functionAlias = functionAlias;
            window.injectivePropertyText = "Yes";
            window.surjectivePropertyText = "Yes";

            window.show();
        }
    }

    Rectangle {
        id: functionLayoutBackground

        anchors.fill: parent
        color: "#ededed"

        RowLayout {
            id: functionLayoutContainer

            anchors.fill: parent

            Text {
                id: alias

                Layout.preferredWidth: 100
                Layout.fillHeight: true
                verticalAlignment: Qt.AlignVCenter
                text: functionAlias
                font.pixelSize: 15
            }

            Text {
                id: expression

                Layout.fillWidth: true
                Layout.fillHeight: true
                verticalAlignment: Qt.AlignVCenter
                text: functionExpression
                font.pixelSize: 15
            }

            Text {
                id: step

                Layout.preferredWidth: 50
                Layout.fillHeight: true
                verticalAlignment: Qt.AlignVCenter
                text: functionStep
                font.pixelSize: 15
            }

            Button {
                id: deleteFunctionButton

                Layout.preferredWidth: 50
                Layout.fillHeight: true
                text: "X"
                font.pixelSize: 15

                onClicked: {
                    ApplicationManager.setCurrentFunctionIndex(index);
                    functionRemoveDialog.open();
                }
            }
        }
    }
}
