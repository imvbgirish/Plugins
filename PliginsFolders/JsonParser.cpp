#include "JsonParser.h"
#include<QDir>
#include<QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include<QCoreApplication>

 JsonParser *JsonParser::m_jsonParser=nullptr;

JsonParser::JsonParser()
{
    qDebug()<<Q_FUNC_INFO;
    // m_baseurl="/home/shankar/Downloads/PliginsFolders/Plugins_build/com/mycompany";
    QString baseUrl = QCoreApplication::applicationDirPath() + "/../../Plugins_build/com/mycompany";
    m_baseurl=baseUrl;
    parseFolders();
}

bool JsonParser::parseFolders()
{
    QDir dir(m_baseurl);
    if (!dir.exists()) {
        qWarning() << "Directory does not exist:" << m_baseurl;
        return false;
    }
    QStringList folderList = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (const QString &folder : folderList) {
        QString jsonFilePath = m_baseurl + "/" + folder + "/info.yaml";
        parseJson(jsonFilePath);
    }
    return true;
}

QList<App*> JsonParser::getAppDataList()
{
    return appDataList;
}

QList<QString> JsonParser::getCategoryList()
{
    return m_categoryList;
}

QString JsonParser::baseurl() const
{
    return m_baseurl;
}

void JsonParser::setBaseurl(const QString &newBaseurl)
{
    m_baseurl = newBaseurl;
}

JsonParser *JsonParser::getInstance()
{
    if(!m_jsonParser)
        m_jsonParser=new JsonParser();
    return m_jsonParser;
}

void JsonParser::parseJson(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open file:" << filePath;
        return;
    }
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (!jsonDoc.isObject()) {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return;
    }
    QJsonObject jsonObj = jsonDoc.object();
    App* app = new App;
    app->setAppName(jsonObj.value("AppName").toString());
    app->setQmlFile(jsonObj.value("PluginName").toString());
    app->setIcon(jsonObj.value("AppIcon").toString());
    app->setPluginPath(jsonObj.value("MainFileQml").toString());
    app->setCategories(jsonObj.value("Category").toString());
    if(!m_categoryList.contains(app->categories()))
    {
        m_categoryList.push_back(app->categories());
        qDebug()<< "categorys data: " <<app->categories();
    }
    appDataList.append(app);
}
