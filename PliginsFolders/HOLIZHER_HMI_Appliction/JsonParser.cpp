#include "JsonParser.h"
#include<QDir>
#include<QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
JsonParser *JsonParser::m_instance=nullptr;
JsonParser::JsonParser(QObject *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO;
    m_baseurl="/home/shankar/HOLIZHER_HMI_Appliction/Apps_json_data";
    parseFolders();
}

JsonParser::~JsonParser()
{
    qDebug() << Q_FUNC_INFO;
}

void JsonParser::parseJson(const QString &filePath)
{
    qDebug() << Q_FUNC_INFO;
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning() << "Could not open file:" << filePath;
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (!jsonDoc.isObject())
    {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    App *appData = new App();
    appData->setAppName(jsonObj.value("AppName").toString());
    appData->setFileName(jsonObj.value("FileName").toString());
    appData->setIcon(jsonObj.value("Icon").toString());
    appData->setCategory(jsonObj.value("category").toString());

    if(!m_categoryList.contains(appData->getCategory()))
    {
        m_categoryList.push_back(appData->getCategory());
        qDebug()<< "categorys data: " <<appData->getCategory();
    }
    m_appDataList.append(appData);
}

bool JsonParser::parseFolders()
{
    qDebug() << Q_FUNC_INFO;
    QDir dir(m_baseurl);
    if (!dir.exists())
    {
        qWarning() << "Directory does not exist:" << m_baseurl;
        return false;
    }

    QStringList folderList = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QString &folder : folderList)
    {
        QString jsonFilePath = m_baseurl + "/" + folder + "/config.yaml";
        parseJson(jsonFilePath);
    }
    return true;
}

QList<App*> JsonParser::getAppDataList()
{
    qDebug() << Q_FUNC_INFO;
    return m_appDataList;
}

QList<QString> JsonParser::getCategoryList()
{
    qDebug() << Q_FUNC_INFO;
    return m_categoryList;
}

JsonParser *JsonParser::getInstace()
{
    if(!m_instance)
        m_instance=new JsonParser();
    return m_instance;
}


