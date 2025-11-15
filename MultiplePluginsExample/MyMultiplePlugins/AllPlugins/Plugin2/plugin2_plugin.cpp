#include "plugin2_plugin.h"

#include "settings.h"

#include <qqml.h>

void Plugin2Plugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.settings
    qmlRegisterType<Settings>(uri, 1, 0, "Settings");
}
