#include "myrectangle_plugin.h"

#include "myitem.h"

#include <qqml.h>

void MyRectanglePlugin::registerTypes(const char *uri)
{
    // @uri MyPlugin
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
}
