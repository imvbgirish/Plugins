#ifndef WHATSAPPPLUGIN_PLUGIN_H
#define WHATSAPPPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class WhatsAppPluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // WHATSAPPPLUGIN_PLUGIN_H
