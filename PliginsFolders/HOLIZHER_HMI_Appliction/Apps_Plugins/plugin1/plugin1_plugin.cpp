#include "plugin1_plugin.h"

#include "MyItem.h"

#include <qqml.h>

void Plugin1Plugin::registerTypes(const char *uri)
{
    // @uri com.pthinks.plugin1
    qmlRegisterType(QUrl("qrc:/DemoExample.qml"), uri, 1, 0, "Harsha");

    // qmlRegisterType<QUrl("qrc:/plugin1/Plugin1Demo.qml")>
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
}
