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

            TextField {
                id: functionRangeMinInput

                Layout.preferredHeight: 30
                Layout.preferredWidth: 30

                placeholderText: "Min"
                verticalAlignment: Qt.AlignVCenter
            }

            TextField {
                id: functionRangeMaxInput

                Layout.preferredHeight: 30
                Layout.preferredWidth: 30

                placeholderText: "Max"
                verticalAlignment: Qt.AlignVCenter
            }
            TextField {
                id: functionStepInput

                Layout.preferredHeight: 30
                Layout.preferredWidth: 30

                placeholderText: "Step"
                verticalAlignment: Qt.AlignVCenter
            }

            Button {
                id: addFunctionButton

                text: "Add Function"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 100
                onClicked: {
                    ApplicationManager.addFunction(functionFormulaInput.text, functionRangeMinInput.text, functionRangeMaxInput.text, functionStepInput.text);
                    functionFormulaInput.text="";
                    functionRangeMinInput.text="";
                    functionRangeMaxInput.text="";
                    functionStepInput.text="";
                }
            }
        }
    }
}
