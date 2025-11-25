#include "CategoryViewModel.h"

CategoryViewModel::CategoryViewModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_categoryDataModel=new CategoryDataModel(this);
    qDebug()<<Q_FUNC_INFO;
}
QHash<int, QByteArray> CategoryViewModel::roleNames() const {
    qDebug()<<Q_FUNC_INFO;

    QHash<int, QByteArray> roles;
    roles[CategoryRole] = "category";
    return roles;
}

int CategoryViewModel::rowCount(const QModelIndex &parent) const {
    qDebug()<<Q_FUNC_INFO;

    if (parent.isValid())
        return 0;
    return m_categoryDataModel->categoryCount();
}

QVariant CategoryViewModel::data(const QModelIndex &index, int role) const {
    qDebug()<<Q_FUNC_INFO;

    if (!index.isValid() || index.row() < 0 || index.row() >= m_categoryDataModel->categoryCount())
        return QVariant();

    if (role == CategoryRole)
        return m_categoryDataModel->getCetegoryIndexData(index.row());

    return QVariant();
}
