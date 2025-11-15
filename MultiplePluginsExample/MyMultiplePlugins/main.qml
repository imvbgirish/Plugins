import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.0
import PluginModels 1.0

Window {
    width: 1200
    height: 800
    visible: true
    title: "Multiple Plugin Loader"

    PluginListModel {
        id: model
    }

    Component.onCompleted: {
        model.loadJson(":/plugins.json")
    }

    RowLayout {
        anchors.fill: parent

        // LEFT SIDE: Plugin display area
        Rectangle {
            id: pluginArea
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.75
            color: "#d9f7ff"

            Loader {
                id: pluginView
                anchors.fill: parent
            }
        }

        // RIGHT SIDE: Buttons list (similar to categories UI)
        Rectangle {
            Layout.fillHeight: true
            Layout.preferredWidth: parent.width * 0.25
            color: "#f0f0f0"

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 20
                spacing: 20

                Label {
                    text: "Plugins"
                    color: "black"
                    font.bold: true
                    font.pixelSize: 26
                    Layout.alignment: Qt.AlignHCenter
                }

                ListView {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    model: model
                    spacing: 10

                    delegate: Button {
                        width: parent.width
                        height: 45
                        text: name

                        background: Rectangle {
                            color: pressed ? "#0078d7" : "#ffffff"
                            border.color: "#cccccc"
                            radius: 8
                        }

                        contentItem: Text {
                            text: name
                            anchors.fill: parent
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.bold: true
                            font.pixelSize: 16
                            color: pressed ? "white" : "black"
                        }

                        onClicked: {
                            loader.loadPlugin(uri, qmlType)
                        }
                    }
                }
            }
        }

        // PURE QML Loader (no C++ conversion issues)
        QtObject {
            id: loader

            property var currentPlugin: null

            function loadPlugin(pluginUri, typeName) {
                console.log("Loading:", pluginUri, typeName)

                // 1️ Destroy previous plugin instance
                if (currentPlugin) {
                    currentPlugin.destroy()
                    currentPlugin = null
                }

                // 2️ No need to reset Loader source since we're not using it for loading

                // 3️ Build dynamic QML
                let qmlCode =
                    "import " + pluginUri + " 1.0;\n" +
                    typeName + " { anchors.fill: parent }"

                // 4️ Create component
                let component = Qt.createComponent("data:text/plain;charset=utf-8," + encodeURIComponent(qmlCode))
                if (component.status === Component.Error) {
                    console.log("Component Error:", component.errorString())
                    return
                }

                // 5️ Create the new plugin object
                let obj = component.createObject(pluginView)
                if (!obj) {
                    console.log("Failed to create plugin object")
                } else {
                    currentPlugin = obj
                }
            }
        }
    }
}
