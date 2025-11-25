#include "InstagramPlugin_plugin.h"

#include "MyItem.h"

#include <qqml.h>

void InstagramPluginPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
    qmlRegisterType(QUrl("qrc:/InstagramItem.qml"), uri, 1, 0, "Instagram");

}
