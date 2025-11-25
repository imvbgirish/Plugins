import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 400
    height: 400
    visible: true
    title: "GridView Example"
    MainWindow{
   //   anchors.fill: parent
    }

    // GridView {
    //     anchors.fill: parent
    //     cellWidth: 100
    //     cellHeight: 100
    //     model: wrapper.categoryViewModel
    //     delegate: Rectangle {
    //         width: 80
    //         height: 80
    //         color: color
    //         border.color: "black"
    //         radius: 8

    //         Text {
    //             id:categoryText
    //             anchors.centerIn: parent
    //             text: category
    //             color: "red"
    //         }
    //         MouseArea{
    //             anchors.fill: parent
    //             onClicked: wrapper.appsFilterModel.setCategoryFilter(categoryText.text)
    //     }

    //     }
    // }
}
