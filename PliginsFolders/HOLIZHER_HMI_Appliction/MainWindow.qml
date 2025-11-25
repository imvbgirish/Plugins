// import QtQuick 2.15
// import QtQuick.Layouts
// import QtQuick.Controls
// import com.example.wrapper 1.0

// Item {
//     id:root
//     anchors.fill: parent

//     Wrapper{
//         id:wrapper
//     }

//     RowLayout{
//         anchors.fill: parent

//         GridView {
//             Layout.fillHeight: true
//             Layout.fillWidth: true
//             cellWidth: 100
//             cellHeight: 100
//             model:wrapper.appsFilterModel
//             delegate: Rectangle {
//                 width: 80
//                 height: 80
//                 color: color
//                 border.color: "black"
//                 radius: 8

//                 Text {
//                     id:appText
//                     anchors.centerIn: parent
//                     text: appName
//                     color: "red"
//                 }
//             }
//         }

//         ListView{
//             Layout.preferredWidth:200
//             Layout.fillHeight: true
//             model: wrapper.categoryViewModel

//             orientation: ListView.Vertical
//             delegate:Rectangle {
//                 width: 80
//                 height: 80
//                 color: color
//                 border.color: "black"
//                 radius: 8


//                 Text {
//                     id:categoryText
//                     anchors.centerIn: parent
//                     text: category
//                     color: "red"
//                 }
//                 MouseArea{
//                     anchors.fill: parent
//                     onClicked: wrapper.appsFilterModel.setCategoryFilter(categoryText.text)
//                 }

//             }
//         }
//     }
// }


import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import com.example.wrapper 1.0

// Item {
//     id: root
//     anchors.fill: parent

//     Wrapper {
//         id: wrapper
//     }

//     RowLayout {
//         anchors.fill: parent

//         // GridView - takes 80% width
//         GridView {
//             id: gridView
//             Layout.preferredWidth: parent.width * 0.8
//             Layout.fillHeight: true

//             model: wrapper.appsFilterModel

//             // Calculate 3 items per row
//             cellWidth: width / 3
//             cellHeight: cellWidth // Make cells square

//             delegate: Rectangle {
//                 width: gridView.cellWidth * 0.9
//                 height: gridView.cellHeight * 0.9
//                 color: "orange"
//                 radius: 8
//                 border.color: "black"

//                 Column {
//                     anchors.centerIn: parent
//                     spacing: 8

//                     Image {
//                         source: icon
//                         width: parent.width * 0.6
//                         height: width
//                         fillMode: Image.PreserveAspectFit
//                     }

//                     Text {
//                         text: appName
//                         color: "white"
//                         font.pixelSize: 14
//                         horizontalAlignment: Text.AlignHCenter
//                         wrapMode: Text.WordWrap
//                         anchors.horizontalCenter: parent.horizontalCenter
//                     }
//                 }
//             }
//         }

//         // ListView - takes 20% width
//         ListView {
//             id: listView
//             Layout.preferredWidth: parent.width * 0.2
//             Layout.fillHeight: true
//             orientation: ListView.Vertical
//             model: wrapper.categoryViewModel

//             delegate: Rectangle {
//                 width: listView.width * 0.9
//                 height: 50
//                 radius: 5
//                 color: "#f0f0f0"
//                 border.color: "#888888"
//                 // anchors.horizontalCenter: parent.horizontalCenter
//                 anchors.margins: 5

//                 Text {
//                     id: categoryText
//                     anchors.centerIn: parent
//                     text: category
//                     color: "#333"
//                     font.bold: true
//                 }

//                 MouseArea {
//                     anchors.fill: parent
//                     onClicked: wrapper.appsFilterModel.setCategoryFilter(categoryText.text)
//                 }
//             }
//         }
//     }
// }
Window {
    width: 1200
    height: 800
    visible: true
    title: qsTr("App Categories Filter")

    property bool animateNow: false // false at startup => no animation; set true on category click

    // At startup → load Production apps only
    Component.onCompleted: {
        wrapper.appsFilterModel.setCategoryFilter("Production")
    }

    RowLayout {
        anchors.fill: parent

        // Left 75%: Apps Grid
        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.75
            color: "skyblue"

            GridView {
                id: gridView
                anchors.fill: parent
                anchors.margins: 20
                cellWidth: 150
                cellHeight: 150
                model: wrapper.appsFilterModel
                clip: true

                delegate: Item {
                    id: delegateRoot
                    width: gridView.cellWidth
                    height: gridView.cellHeight

                    opacity: animateNow ? 0 : 1
                    scale:   animateNow ? 0.5 : 1

                    Column {
                        anchors.centerIn: parent
                        spacing: 4   // reduced gap between icon and text

                        Image {
                            id: iconId
                            source: icon
                            width: gridView.cellWidth
                            height: 70
                            fillMode: Image.PreserveAspectFit
                            scale: 1.0

                            Behavior on scale {
                                NumberAnimation { duration: 150; easing.type: Easing.OutQuad }
                            }

                            MouseArea {
                                anchors.fill: parent
                                hoverEnabled: true
                                onEntered: iconId.scale = 1.2
                                onExited: iconId.scale = 1.0
                                onClicked: console.log("Clicked App:", appName)
                            }
                        }

                        Text {
                            text: appName
                            font.pixelSize: 14
                            color: "black"
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width
                        }
                    }

                    SequentialAnimation {
                        id: popIn
                        running: false
                        PauseAnimation { duration: index * 100 }
                        ParallelAnimation {
                            NumberAnimation { target: delegateRoot; property: "opacity"; to: 1; duration: 300; easing.type: Easing.OutQuad }
                            NumberAnimation { target: delegateRoot; property: "scale";   to: 1; duration: 300; easing.type: Easing.OutBack }
                        }
                    }

                    Component.onCompleted: {
                        if (animateNow) popIn.start()
                    }
                }
            }
        }

        // Right 25%: Categories
        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.25
            color: "#e0e0e0"
            radius: 5

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 20
                spacing: parent.height * 0.03

                Label {
                    text: "Categories"
                    font.bold: true
                    font.pixelSize: parent.height * 0.04
                    Layout.alignment: Qt.AlignHCenter
                }

                Repeater {
                    model: ["Production", "Setup", "Settings", "Maintenance"]

                    Button {
                        Layout.alignment: Qt.AlignHCenter
                        Layout.preferredWidth: parent.width * 0.8
                        Layout.preferredHeight: parent.height * 0.12

                        background: Rectangle {
                            color: pressed ? "#0078d7" : "#ffffff"
                            border.color: "#cccccc"
                            radius: 8
                        }

                        contentItem: Text {
                            text: modelData
                            color: pressed ? "#ffffff" : "#333333"
                            font.pixelSize: parent.height * 0.3
                            font.bold: true
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            anchors.fill: parent
                        }

                        onClicked: {
                            animateNow = true
                            wrapper.appsFilterModel.setCategoryFilter(modelData)
                        }
                    }
                }
            }
        }
    }
}
