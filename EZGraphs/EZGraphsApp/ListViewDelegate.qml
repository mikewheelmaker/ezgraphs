import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Item {
    id: itemContainer

    width: listViewContainer.width
    height: 10

    RowLayout {
        id: layoutContainer

        anchors.fill: parent
        spacing: 0

        Rectangle {
            id: functionExpressionRectangle

            Layout.fillHeight: true
            Layout.fillWidth: true

            RowLayout {
                id: functionLayoutContainer

                anchors.fill: parent

                Text {
                    id: alias

                    Layout.fillHeight: true
                    Layout.preferredWidth: 100
                    text: functionAlias
                }

                Text {
                    id: expression

                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    text: functionExpression
                }

                Text {
                    id: step

                    Layout.fillHeight: true
                    Layout.preferredWidth: 30
                    text: functionStep
                }

                Button {
                    id: deleteFunctionButton

                    Layout.preferredWidth: 30
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignRight
                    text: "X"

                    onClicked: ApplicationManager.removeFunction(index)
                }
            }
        }
    }
}
