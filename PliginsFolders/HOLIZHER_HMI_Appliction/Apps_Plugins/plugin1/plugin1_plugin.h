#ifndef PLUGIN1_PLUGIN_H
#define PLUGIN1_PLUGIN_H

#include <QQmlExtensionPlugin>

class Plugin1Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PLUGIN1_PLUGIN_H
