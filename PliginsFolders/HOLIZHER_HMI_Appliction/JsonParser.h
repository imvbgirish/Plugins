#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QObject>
#include"App.h"

class JsonParser : public QObject
{
    Q_OBJECT
public:
    ~JsonParser();

    bool parseFolders();
    QList<App *> getAppDataList();
    QList<QString> getCategoryList();
    static JsonParser* getInstace();

private:
    explicit JsonParser(QObject *parent = nullptr);

    void parseJson(const QString &filePath);

private:
    QString m_baseurl;
    QList<App*> m_appDataList;
    QList<QString> m_categoryList;
    static JsonParser *m_instance;
};

#endif // JSONPARSER_H
