#include "plugin4_plugin.h"

#include "youtube.h"

#include <qqml.h>

void Plugin4Plugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.youtube
    qmlRegisterType<Youtube>(uri, 1, 0, "Youtube");
}
