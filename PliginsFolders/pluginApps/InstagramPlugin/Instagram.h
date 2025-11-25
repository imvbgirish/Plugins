#ifndef INSTAGRAM_H
#define INSTAGRAM_H

#include <QObject>

class Instagram : public QObject
{
    Q_OBJECT
public:
    explicit Instagram(QObject *parent = nullptr);

signals:
};

#endif // INSTAGRAM_H
