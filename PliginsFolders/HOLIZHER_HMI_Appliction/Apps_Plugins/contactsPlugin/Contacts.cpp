#include "Contacts.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
Contacts::Contacts(QObject *parent)
    : QObject{parent}
{
    QString configFilePath = "/home/pthinks/Desktop/Apps_plugin-Example/contacts/config.yaml";
    readConfigFile(configFilePath);
}

QString Contacts::plugin() const
{
    return m_plugin;
}

void Contacts::setPlugin(const QString &newPlugin)
{
    if (m_plugin == newPlugin)
        return;
    m_plugin = newPlugin;
    emit pluginChanged();
}

QString Contacts::icon() const
{
    return m_icon;
}

void Contacts::setIcon(const QString &newIcon)
{
    if (m_icon == newIcon)
        return;
    m_icon = newIcon;
    emit iconChanged();
}

QString Contacts::fileName() const
{
    return m_fileName;
}

void Contacts::setFileName(const QString &newFileName)
{
    if (m_fileName == newFileName)
        return;
    m_fileName = newFileName;
    emit fileNameChanged();
}

QString Contacts::appName() const
{
    return m_appName;
}

void Contacts::setAppName(const QString &newAppName)
{
    if (m_appName == newAppName)
        return;
    m_appName = newAppName;
    emit appNameChanged();
}

void Contacts::readConfigFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file for reading:" << filePath;
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(content.toUtf8());
    if (!doc.isObject()) {
        qWarning() << "Invalid JSON format in file:" << filePath;
        return;
    }

    QJsonObject jsonObj = doc.object();
    if (jsonObj.contains("Plugin")) {
        setPlugin(jsonObj["Plugin"].toString());
    }
    if (jsonObj.contains("Icon")) {
        setIcon(jsonObj["Icon"].toString());
    }
    if (jsonObj.contains("FileName")) {
        setFileName(jsonObj["FileName"].toString());
    }
    if (jsonObj.contains("AppName")) {
        setAppName(jsonObj["AppName"].toString());
    }
}
