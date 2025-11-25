#ifndef JSONPARSER_H
#define JSONPARSER_H
#include"App.h"
#include<QString>
#include<QList>

struct AppData {
    QString appName;
    QString fileName;
    QString icon;
    QString Category;
};

class JsonParser
{
public:
    bool parseFolders();
    QList<App*> getAppDataList();
    QList<QString> getCategoryList();

    QString baseurl() const;
    void setBaseurl(const QString &newBaseurl);
    static JsonParser* getInstance();

private:
    QString m_baseurl;
    QList<App*> appDataList;
    void parseJson(const QString &filePath);
    explicit JsonParser();
    static JsonParser *m_jsonParser;
    QStringList m_categoryList;
};



#endif // JSONPARSER_H
