#ifndef APPDATAMODEL_H
#define APPDATAMODEL_H

#include <QObject>
#include<QList>
#include"JsonParser.h"
class AppDataModel : public QObject
{
    Q_OBJECT
public:
    explicit AppDataModel(QObject *parent = nullptr);
    int getAppCount();
    App* getAppIndexData(int index);
private:
    JsonParser *m_parser;
    QList<App*> m_appDataList;
};

#endif // APPDATAMODEL_H
