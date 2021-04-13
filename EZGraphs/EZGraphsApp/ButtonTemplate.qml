import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import QtQml

Button {
    property string buttonText
    property int buttonWidth
    property int buttonHeight
    property int buttonFunction

    text: buttonText
    width: buttonWidth
    height: buttonHeight
    onClicked: ButtonFunctionSupplier.onClickedSelectFunction(buttonFunction)
}
