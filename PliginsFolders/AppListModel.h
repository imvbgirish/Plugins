#ifndef APPLISTMODEL_H
#define APPLISTMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include<JsonParser.h>
class AppListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    AppListModel();
    enum AppsRole {
        AppName = 1,
        ICON,
        QmlFile,
        PluginPath,
        Category
    };

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

    QList<App *> getAppsData() const;
    void setAppsData(const QList<App *> &newAppsData);

private:
    QList<App*> appsData;
    JsonParser* m_jsonarser;

    // QAbstractItemModel interface
public:
    virtual QHash<int, QByteArray> roleNames() const override;
};

#endif // APPLISTMODEL_H
