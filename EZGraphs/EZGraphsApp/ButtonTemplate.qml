import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Button {
    property string buttonText: ""
    property int buttonWidth: 0
    property int buttonHeight: 0
    property int buttonFunction: 0

    text: buttonText
    width: buttonWidth
    height: buttonHeight

    onClicked: ButtonFunctionSupplier.onClickedSelectFunction(buttonFunction)
}
