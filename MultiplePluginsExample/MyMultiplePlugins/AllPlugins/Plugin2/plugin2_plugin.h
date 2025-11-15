#ifndef PLUGIN2_PLUGIN_H
#define PLUGIN2_PLUGIN_H

#include <QQmlExtensionPlugin>

class Plugin2Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PLUGIN2_PLUGIN_H
