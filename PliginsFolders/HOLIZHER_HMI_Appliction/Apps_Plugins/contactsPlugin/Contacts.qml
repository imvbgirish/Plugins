import QtQuick 2.15
import QtQuick.Window 2.15

Rectangle{
    width:300
    height:200
    border.color: "red"
    Text {
        id: _text
        text: qsTr("contact qml file loaded")
    }
}

