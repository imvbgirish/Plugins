import QtQuick
import Plugin 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Girish{
        id: giri
        name: "Girish"
        height: 100
        width: 100
        Component.onCompleted: {
            display()
        }
    }

    GirishControls {
        id: qmlGiri
    }

    Component.onCompleted: {
        console.log("Plugin loaded")
    }
}
