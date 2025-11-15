#include "plugin5_plugin.h"

#include "music.h"

#include <qqml.h>

void Plugin5Plugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.music
    qmlRegisterType<Music>(uri, 1, 0, "Music");
}
