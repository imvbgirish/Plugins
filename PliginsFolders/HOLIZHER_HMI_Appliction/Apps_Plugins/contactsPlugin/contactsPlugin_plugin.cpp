#include "contactsPlugin_plugin.h"

#include "MyItem.h"
#include"Contacts.h"
#include <qqml.h>

void ContactsPluginPlugin::registerTypes(const char *uri)
{
    // @uri com.contacts.qml
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
     qmlRegisterType<Contacts>(uri, 1, 0, "Contacts_class");
    qmlRegisterType(QUrl("qrc:/Contacts.qml"), uri, 1, 0, "Contacts");

}
