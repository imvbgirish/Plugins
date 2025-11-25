#include "App.h"

App::App(QObject *parent)
    : QObject{parent}
{}

QString App::getAppName() const
{
    return appName;
}

void App::setAppName(const QString &newAppName)
{
    if (appName == newAppName)
        return;
    appName = newAppName;
    emit appNameChanged();
}

QString App::getFileName() const
{
    return fileName;
}

void App::setFileName(const QString &newFileName)
{
    if (fileName == newFileName)
        return;
    fileName = newFileName;
    emit fileNameChanged();
}

QString App::getIcon() const
{
    return icon;
}

void App::setIcon(const QString &newIcon)
{
    if (icon == newIcon)
        return;
    icon = newIcon;
    emit iconChanged();
}

QString App::getCategory() const
{
    return category;
}

void App::setCategory(const QString &newCategory)
{
    if (category == newCategory)
        return;
    category = newCategory;
    emit categoryChanged();
}
