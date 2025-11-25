#ifndef APPVIEWMODEL_H
#define APPVIEWMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include"AppDataModel.h"
class AppViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit AppViewModel(QObject *parent = nullptr);

    enum AppsRole {
        AppName = 1,
        ICON,
        QmlFile,
        PluginPath,
        Category
    };

    // QAbstractItemModel interface
public:


    QList<App *> getAppsData() const;
    void setAppsData(const QList<App *> &newAppsData);
private:
    AppDataModel *appDataModel;

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const override;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
};

#endif // APPVIEWMODEL_H
