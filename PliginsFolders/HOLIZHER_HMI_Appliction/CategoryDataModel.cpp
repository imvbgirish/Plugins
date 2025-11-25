#include "CategoryDataModel.h"
#include<QDebug>
CategoryDataModel::CategoryDataModel(QObject *parent)
    : QObject{parent}
{

    m_parser=JsonParser::getInstace();
    m_categoryList=m_parser->getCategoryList();
    qDebug()<<Q_FUNC_INFO << "Category list size: " << m_categoryList.size();
    for(auto listData :m_categoryList ){
        qDebug()<<" Category: " << listData;
    }
}

int CategoryDataModel::categoryCount()
{
    return m_categoryList.size();
}

QString CategoryDataModel::getCetegoryIndexData(int index)
{
    return m_categoryList.at(index);
}
