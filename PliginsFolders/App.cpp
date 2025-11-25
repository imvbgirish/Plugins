#include "App.h"

App::App(QObject *parent)
    : QObject{parent}
{}

QString App::appName() const
{
    return m_appName;
}

void App::setAppName(const QString &newAppName)
{
    if (m_appName == newAppName)
        return;
    m_appName = newAppName;
    emit appNameChanged();
}

QString App::icon() const
{
    return m_icon;
}

void App::setIcon(const QString &newIcon)
{
    if (m_icon == newIcon)
        return;
    m_icon = newIcon;
    emit iconChanged();
}

QString App::qmlFile() const
{
    return m_qmlFile;
}

void App::setQmlFile(const QString &newQmlFile)
{
    if (m_qmlFile == newQmlFile)
        return;
    m_qmlFile = newQmlFile;
    emit qmlFileChanged();
}

QString App::pluginPath() const
{
    return m_pluginPath;
}

void App::setPluginPath(const QString &newPluginPath)
{
    if (m_pluginPath == newPluginPath)
        return;
    m_pluginPath = newPluginPath;
    emit pluginPathChanged();
}

QString App::categories() const
{
    return m_categories;
}

void App::setCategories(const QString &newCategories)
{
    if (m_categories == newCategories)
        return;
    m_categories = newCategories;
    emit categoriesChanged();
}
