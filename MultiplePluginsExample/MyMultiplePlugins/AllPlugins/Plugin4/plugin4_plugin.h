#ifndef PLUGIN4_PLUGIN_H
#define PLUGIN4_PLUGIN_H

#include <QQmlExtensionPlugin>

class Plugin4Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PLUGIN4_PLUGIN_H
