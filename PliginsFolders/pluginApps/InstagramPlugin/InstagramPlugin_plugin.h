#ifndef INSTAGRAMPLUGIN_PLUGIN_H
#define INSTAGRAMPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class InstagramPluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // INSTAGRAMPLUGIN_PLUGIN_H
