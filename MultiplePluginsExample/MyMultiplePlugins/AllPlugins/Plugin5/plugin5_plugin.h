#ifndef PLUGIN5_PLUGIN_H
#define PLUGIN5_PLUGIN_H

#include <QQmlExtensionPlugin>

class Plugin5Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PLUGIN5_PLUGIN_H
