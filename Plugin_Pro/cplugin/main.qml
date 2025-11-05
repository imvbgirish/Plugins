import QtQuick 2.12
import com.mycompany.qmlcomponents 1.0

Window{
    id: root
    visible: true
    height: 400
    width: 400

    MyItem{
        name: "Girish"
        Component.onCompleted: display()
    }
}


