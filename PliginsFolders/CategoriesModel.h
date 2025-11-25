#ifndef CATEGORIESMODEL_H
#define CATEGORIESMODEL_H

#include "JsonParser.h"
#include "qabstractitemmodel.h"

class CategoriesModel: public QAbstractListModel {
    Q_OBJECT
public:
    enum Roles { CategoryRole = Qt::UserRole + 1 };
    QHash<int, QByteArray> roleNames() const override ;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;

    QVariant data(const QModelIndex &index, int role) const override ;

    void setCategories(const QStringList &cats) ;
private:
    QStringList m_categories;
    JsonParser* m_jsonParser;

public:
   explicit CategoriesModel(QObject *parent = nullptr);
};

#endif // CATEGORIESMODEL_H
