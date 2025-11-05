import QtQuick 2.15
import QtQuick.Window 2.15
import com.mycompany.qmlcomponents

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MyItem{
        height: 100
        width: 100
        x: 100
        y: 100
        name: "Girish"
        Component.onCompleted: display()
    }
}
