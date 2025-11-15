#ifndef PLUGINLISTMODEL_H
#define PLUGINLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

struct PluginInfo {
    QString name;
    QString uri;
    QString qmlType;
};

class PluginListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    PluginListModel();
    ~PluginListModel();

    enum Roles {
        NameRole = Qt::UserRole + 1,
        UriRole,
        QmlTypeRole
    };

    // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void loadJson(const QString &path);

private:
    QList<PluginInfo> m_list;
};

#endif // PLUGINLISTMODEL_H
