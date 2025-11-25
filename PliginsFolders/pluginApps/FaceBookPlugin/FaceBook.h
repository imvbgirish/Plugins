#ifndef FACEBOOK_H
#define FACEBOOK_H

#include <QObject>

class FaceBook : public QObject
{
    Q_OBJECT
public:
    explicit FaceBook(QObject *parent = nullptr);

signals:
};

#endif // FACEBOOK_H
