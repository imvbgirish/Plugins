#ifndef CONTACTSPLUGIN_PLUGIN_H
#define CONTACTSPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class ContactsPluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // CONTACTSPLUGIN_PLUGIN_H
