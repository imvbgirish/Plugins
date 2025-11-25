#include "App1Plugin_plugin.h"

#include "MyItem.h"

#include <qqml.h>

void App1PluginPlugin::registerTypes(const char *uri)
{
    // @uri com.pthinks.app1
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
    qmlRegisterType(QUrl("qrc:/MyWindow.qml"), "MyApp.Components", 1, 0, "MyComponent");

}
