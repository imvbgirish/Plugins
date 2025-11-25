#ifndef FACEBOOKPLUGIN_PLUGIN_H
#define FACEBOOKPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class FaceBookPluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // FACEBOOKPLUGIN_PLUGIN_H
