#include "pluginlistmodel.h"

PluginListModel::PluginListModel() {}

PluginListModel::~PluginListModel()
{
    m_list.clear();
}

int PluginListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

QVariant PluginListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return {};

    const PluginInfo &p = m_list.at(index.row());

    switch(role){
    case NameRole:
        return p.name;
    case UriRole:
        return p.uri;
    case QmlTypeRole:
        return p.qmlType;
    default:
        return QVariant();
    }
    return {};
}

QHash<int, QByteArray> PluginListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(NameRole, "name");
    roles.insert(UriRole, "uri");
    roles.insert(QmlTypeRole, "qmlType");
    return roles;
}

void PluginListModel::loadJson(const QString &path)
{
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly))
        return;

    QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
    QJsonArray arr = doc.array();

    beginResetModel();
    m_list.clear();

    for (auto v : std::as_const(arr)) {
        QJsonObject o = v.toObject();
        PluginInfo p;
        p.name = o["AppName"].toString();
        p.uri = o["PluginUri"].toString();
        p.qmlType = o["QmlType"].toString();
        m_list.append(p);
    }

    endResetModel();
}
