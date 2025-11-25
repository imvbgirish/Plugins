import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.12
import com.mycompany.WhatsApp 1.0
import com.mycompany.Instagram 1.0
import com.mycompany.FaceBook 1.0
// import com.mycompany.qmlcomponents 1.0

Window {
    width: 1200
    height: 800
    visible: true
    title: qsTr("App Categories Filter")

    property bool animateNow: false // false at startup => no animation; set true on category click

    Component.onCompleted: {
        wrapper.setCategoryFilter("Production")
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
                model: wrapper.filteredAppModel
                clip: true

                delegate: Item {
                    id: delegateRoot
                    width: gridView.cellWidth
                    height: gridView.cellHeight

                    opacity: animateNow ? 0 : 1
                    scale:   animateNow ? 0.5 : 1

                    Column {
                        anchors.centerIn: parent
                        spacing: 10

                        Image {
                            id: iconId
                            source: model.icon
                            width: gridView.cellWidth
                            height: 75
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
                                onClicked: console.log("Clicked App:", model.appName)
                            }
                        }

                        Text {
                            text: model.appName
                            font.pixelSize: 14
                            color: "black"
                            anchors.horizontalCenter: iconId.horizontalCenter
                        }
                    }

                    // Animation for category changes
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
                        if (animateNow) popIn.start();
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
                            wrapper.setCategoryFilter(modelData)
                        }
                    }
                }
            }
        }
    }
}
