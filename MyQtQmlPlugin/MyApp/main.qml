import QtQuick
import MyPlugin 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyItem{
        id: itm
        Component.onCompleted: itm.display()
    }
}
