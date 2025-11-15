#include "plugin1_plugin.h"

#include "camera.h"

#include <qqml.h>

void Plugin1Plugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.camera
    qmlRegisterType<Camera>(uri, 1, 0, "Camera");
}
