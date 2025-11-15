#include "plugin3_plugin.h"

#include "maps.h"

#include <qqml.h>

void Plugin3Plugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.maps
    qmlRegisterType<Maps>(uri, 1, 0, "Maps");
}
