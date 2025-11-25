#ifndef CATEGORYVIEWMODEL_H
#define CATEGORYVIEWMODEL_H

#include <QAbstractListModel>
#include"CategoryDataModel.h"
class CategoryViewModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CategoryViewModel(QObject *parent = nullptr);


    enum Roles { CategoryRole = Qt::UserRole + 1 };
    QHash<int, QByteArray> roleNames() const override ;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override ;

    QVariant data(const QModelIndex &index, int role) const override ;
private:
    CategoryDataModel *  m_categoryDataModel;
};


#endif // CATEGORYVIEWMODEL_H
