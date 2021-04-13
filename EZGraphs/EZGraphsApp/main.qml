import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 1280
    height: 720
    visible: true
    //visibility: Qt.WindowFullScreen

    title: qsTr("EZGraphs")

    ButtonTemplate {
        id: testButton
        buttonText: "something"
        buttonWidth: 100
        buttonHeight: 30
        buttonFunction: 0
    }
}
