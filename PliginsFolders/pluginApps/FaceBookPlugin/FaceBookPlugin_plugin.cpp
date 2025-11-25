#include "FaceBookPlugin_plugin.h"

#include "MyItem.h"

#include <qqml.h>

void FaceBookPluginPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
    qmlRegisterType(QUrl("qrc:/FaceBookItem.qml"), uri, 1, 0, "FacebookQml");
}
