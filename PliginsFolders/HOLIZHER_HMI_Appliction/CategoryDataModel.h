#ifndef CATEGORYDATAMODEL_H
#define CATEGORYDATAMODEL_H

#include <QObject>
#include<QList>
#include"JsonParser.h"
class CategoryDataModel : public QObject
{
    Q_OBJECT
public:
    explicit CategoryDataModel(QObject *parent = nullptr);
    int categoryCount();
    QString getCetegoryIndexData(int index);
private:
    JsonParser *m_parser;
    QList<QString> m_categoryList;
};

#endif // CATEGORYDATAMODEL_H
