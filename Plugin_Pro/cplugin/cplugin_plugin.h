#ifndef CPLUGIN_PLUGIN_H
#define CPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class CpluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // CPLUGIN_PLUGIN_H
