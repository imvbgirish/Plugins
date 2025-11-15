#ifndef PLUGIN3_PLUGIN_H
#define PLUGIN3_PLUGIN_H

#include <QQmlExtensionPlugin>

class Plugin3Plugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PLUGIN3_PLUGIN_H
