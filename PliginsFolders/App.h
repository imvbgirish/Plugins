#ifndef APP_H
#define APP_H

#include <QObject>

class App : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString appName READ appName WRITE setAppName NOTIFY appNameChanged FINAL)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged FINAL)
    Q_PROPERTY(QString qmlFile READ qmlFile WRITE setQmlFile NOTIFY qmlFileChanged FINAL)
    Q_PROPERTY(QString pluginPath READ pluginPath WRITE setPluginPath NOTIFY pluginPathChanged FINAL)
    Q_PROPERTY(QString categories READ categories WRITE setCategories NOTIFY categoriesChanged FINAL)
public:
    explicit App(QObject *parent = nullptr);

    QString appName() const;
    void setAppName(const QString &newAppName);

    QString icon() const;
    void setIcon(const QString &newIcon);

    QString qmlFile() const;
    void setQmlFile(const QString &newQmlFile);

    QString pluginPath() const;
    void setPluginPath(const QString &newPluginPath);

    QString categories() const;
    void setCategories(const QString &newCategories);

signals:

    void appNameChanged();

    void iconChanged();

    void qmlFileChanged();

    void pluginPathChanged();

    void categoriesChanged();

private:
    QString m_appName;
    QString m_icon;
    QString m_qmlFile;
    QString m_pluginPath;
    QString m_categories;
};

#endif // APP_H
