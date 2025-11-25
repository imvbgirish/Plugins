#include "AppListModel.h"
#include<QDebug>
AppListModel::AppListModel() {
    qDebug()<<Q_FUNC_INFO;
    m_jsonarser = JsonParser::getInstance();
    this->setAppsData(m_jsonarser->getAppDataList());
    for (const auto &app : appsData) {
        qDebug() << "App Name:" << app->appName()
                 << "Icon:" << app->icon()
                 << "Category:" << app->categories();
    }
}

int AppListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return appsData.size();
}

QVariant AppListModel::data(const QModelIndex &index, int role) const
{
    qDebug()<<Q_FUNC_INFO;
    switch (role) {
    case AppsRole::AppName:
        return appsData.at(index.row())->appName();
        break;
    case AppsRole::ICON:
        return appsData.at(index.row())->icon();
        break;
    case AppsRole::QmlFile:
        return appsData.at(index.row())->qmlFile();
        break;
    case AppsRole::PluginPath:
        return appsData.at(index.row())->pluginPath();
        break;
    case AppsRole::Category:
        return appsData.at(index.row())->categories();
        break;
    default:
        break;
    }
    return QVariant();
}

QList<App *> AppListModel::getAppsData() const
{
    return appsData;
}

void AppListModel::setAppsData(const QList<App *> &newAppsData)
{
    appsData = newAppsData;
}

QHash<int, QByteArray> AppListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[AppsRole::AppName] = "appName";
    roles[AppsRole::ICON] = "icon";
    roles[AppsRole::PluginPath] = "pluginPath";
    roles[AppsRole::QmlFile] = "qmlPath";
    roles[AppsRole::Category] = "category";
    return roles;
}
