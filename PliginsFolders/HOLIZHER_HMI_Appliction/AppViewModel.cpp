#include "AppViewModel.h"

AppViewModel::AppViewModel(QObject *parent)
    : QAbstractListModel{parent}
{
    appDataModel=new AppDataModel(this);
}
int AppViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return appDataModel->getAppCount();
}

QVariant AppViewModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO;
    App *appData = appDataModel->getAppIndexData(index.row());
    switch (role) {
    case AppsRole::AppName:
        return appData->getAppName();
        break;
    case AppsRole::ICON:
        return appData->getIcon();
        break;
    case AppsRole::QmlFile:
        return appData->getFileName();
        break;
    case AppsRole::PluginPath:
        return "";
        break;
    case AppsRole::Category:
        return appData->getCategory();
        break;
    default:
        break;
    }
    return QVariant();
}

// QList<App *> AppViewModel::getAppsData() const
// {
//     return appsData;
// }

// void AppViewModel::setAppsData(const QList<App *> &newAppsData)
// {
//     appsData = newAppsData;
// }

QHash<int, QByteArray> AppViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[AppsRole::AppName] = "appName";
    roles[AppsRole::ICON] = "icon";
    roles[AppsRole::PluginPath] = "pluginPath";
    roles[AppsRole::QmlFile] = "qmlPath";
    roles[AppsRole::Category] = "category";
    return roles;
}
