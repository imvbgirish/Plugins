#include "plugin6_plugin.h"

#include "chrome.h"

#include <qqml.h>

void Plugin6Plugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.chrome
    qmlRegisterType<Chrome>(uri, 1, 0, "Chrome");
}
