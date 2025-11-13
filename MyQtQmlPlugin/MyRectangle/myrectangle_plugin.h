#ifndef MYRECTANGLE_PLUGIN_H
#define MYRECTANGLE_PLUGIN_H

#include <QQmlExtensionPlugin>

class MyRectanglePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // MYRECTANGLE_PLUGIN_H
