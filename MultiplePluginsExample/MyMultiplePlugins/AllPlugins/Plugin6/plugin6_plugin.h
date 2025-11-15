#ifndef PLUGIN6_PLUGIN_H
#define PLUGIN6_PLUGIN_H

#include <QQmlExtensionPlugin>

class Plugin6Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PLUGIN6_PLUGIN_H
