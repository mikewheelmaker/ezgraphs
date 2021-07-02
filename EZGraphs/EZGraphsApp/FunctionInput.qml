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
                id: functionAliasInput

                Layout.preferredWidth: 150
                Layout.preferredHeight: 30

                placeholderText: "Enter alias here"
                font.pixelSize: 15
                verticalAlignment: Qt.AlignVCenter
            }

            ComboBox {
                id: functionFormulaSelect

                Layout.fillWidth: true
                Layout.preferredHeight: 30

                currentIndex: 0
                model: [ "sin(x)", "cos(x)", "tan(x)", "exp(x)", "log(x)", "x", "x^2", "x^3", "1/x" ]
            }

            TextField {
                id: functionRangeMinInput

                Layout.preferredWidth: 40
                Layout.preferredHeight: 30

                placeholderText: "Min"
                font.pixelSize: 15
                verticalAlignment: Qt.AlignVCenter
            }

            TextField {
                id: functionRangeMaxInput

                Layout.preferredWidth: 40
                Layout.preferredHeight: 30

                placeholderText: "Max"
                font.pixelSize: 15
                verticalAlignment: Qt.AlignVCenter
            }

            TextField {
                id: functionStepInput

                Layout.preferredWidth: 40
                Layout.preferredHeight: 30

                placeholderText: "Step"
                font.pixelSize: 15
                verticalAlignment: Qt.AlignVCenter
            }

            Button {
                id: addFunctionButton

                text: "Add Function"
                font.pixelSize: 15
                Layout.preferredWidth: 100
                Layout.preferredHeight: 30
                onClicked: {
                    if(functionAliasInput.text.length != 0)
                    {
                        ApplicationManager.addFunction(functionAliasInput.text, functionFormulaSelect.currentIndex,
                                                       functionRangeMinInput.text, functionRangeMaxInput.text,
                                                       functionStepInput.text);
                        functionAliasInput.text = "";
                        functionAliasInput.placeholderText = "Enter alias here"
                        functionAliasInput.placeholderTextColor = "black"
                        functionRangeMinInput.text="";
                        functionRangeMaxInput.text="";
                        functionStepInput.text="";
                    }
                    else
                    {
                        functionAliasInput.placeholderText = "MANDATORY"
                        functionAliasInput.placeholderTextColor = "red"
                    }
                }
            }
        }
    }
}
