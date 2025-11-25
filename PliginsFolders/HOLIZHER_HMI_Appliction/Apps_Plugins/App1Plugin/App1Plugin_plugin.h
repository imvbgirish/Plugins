#ifndef APP1PLUGIN_PLUGIN_H
#define APP1PLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class App1PluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // APP1PLUGIN_PLUGIN_H
