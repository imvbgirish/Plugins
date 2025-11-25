#include "ChromePlugin_plugin.h"

#include "MyItem.h"

#include <qqml.h>

void ChromePluginPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");

    qmlRegisterType(QUrl("qrc:/ChromeItem.qml"), uri, 1, 0, "ChromeQml");

}
