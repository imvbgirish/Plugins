#ifndef CHROME_H
#define CHROME_H

#include <QObject>

class Chrome : public QObject
{
    Q_OBJECT
public:
    explicit Chrome(QObject *parent = nullptr);

signals:
};

#endif // CHROME_H
