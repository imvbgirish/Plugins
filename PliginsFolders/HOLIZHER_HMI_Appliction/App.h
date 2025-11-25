#ifndef APP_H
#define APP_H

#include <QObject>

class App : public QObject
{
    Q_OBJECT
public:
    explicit App(QObject *parent = nullptr);

    QString getAppName() const;
    void setAppName(const QString &newAppName);

    QString getFileName() const;
    void setFileName(const QString &newFileName);

    QString getIcon() const;
    void setIcon(const QString &newIcon);

    QString getCategory() const;
    void setCategory(const QString &newCategory);

private:
    QString appName;
    QString fileName;
    QString icon;
    QString category;
    Q_PROPERTY(QString appName READ getAppName WRITE setAppName NOTIFY appNameChanged FINAL)

    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged FINAL)

    Q_PROPERTY(QString icon READ getIcon WRITE setIcon NOTIFY iconChanged FINAL)

    Q_PROPERTY(QString category READ getCategory WRITE setCategory NOTIFY categoryChanged FINAL)

signals:
    void appNameChanged();
    void fileNameChanged();
    void iconChanged();
    void categoryChanged();
};

#endif // APP_H
