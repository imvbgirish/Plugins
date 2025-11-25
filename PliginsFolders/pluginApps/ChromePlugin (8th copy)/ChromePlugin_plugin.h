#ifndef CHROMEPLUGIN_PLUGIN_H
#define CHROMEPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class ChromePluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // CHROMEPLUGIN_PLUGIN_H
