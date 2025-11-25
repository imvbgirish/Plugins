#include "AppDataModel.h"
#include<QDebug>
AppDataModel::AppDataModel(QObject *parent)
    : QObject{parent}
{
    m_parser=JsonParser::getInstace();
    m_appDataList= m_parser->getAppDataList();
    qDebug()<<Q_FUNC_INFO<<"app data list "<<m_appDataList.size();
}

int AppDataModel::getAppCount()
{
    return m_appDataList.size();
}

App *AppDataModel::getAppIndexData(int index)
{
    return m_appDataList.at(index);
}
