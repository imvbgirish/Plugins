#include "CategoriesModel.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

CategoriesModel::CategoriesModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_jsonParser = JsonParser::getInstance();
    m_categories = m_jsonParser->getCategoryList();
}

QHash<int, QByteArray> CategoriesModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[CategoryRole] = "category";
    return roles;
}

int CategoriesModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    return m_categories.count();
}

QVariant CategoriesModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= m_categories.size())
        return QVariant();

    if (role == CategoryRole)
        return m_categories.at(index.row());

    return QVariant();
}

void CategoriesModel::setCategories(const QStringList &cats) {
    qDebug() << "size ----"<<m_categories.size();
    beginResetModel();
    m_categories = cats;
    endResetModel();
    qDebug() << "size 111----"<<m_categories.size();

}

