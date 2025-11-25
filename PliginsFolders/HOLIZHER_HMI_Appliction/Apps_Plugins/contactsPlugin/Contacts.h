#ifndef CONTACTS_H
#define CONTACTS_H

#include <QObject>

class Contacts : public QObject
{
    Q_OBJECT
public:
    explicit Contacts(QObject *parent = nullptr);

    QString plugin() const;
    void setPlugin(const QString &newPlugin);

    QString icon() const;
    void setIcon(const QString &newIcon);

    QString fileName() const;
    void setFileName(const QString &newFileName);

    QString appName() const;
    void setAppName(const QString &newAppName);

signals:
    void pluginChanged();

    void iconChanged();

    void fileNameChanged();

    void appNameChanged();

private:
    QString m_plugin;
    QString m_icon;
    QString m_fileName;
    QString m_appName;
    void readConfigFile(const QString &filePath);
    Q_PROPERTY(QString plugin READ plugin WRITE setPlugin NOTIFY pluginChanged FINAL)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged FINAL)
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged FINAL)
    Q_PROPERTY(QString appName READ appName WRITE setAppName NOTIFY appNameChanged FINAL)
};

#endif // CONTACTS_H
