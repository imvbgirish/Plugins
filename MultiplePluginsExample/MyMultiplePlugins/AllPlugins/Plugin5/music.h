#ifndef MUSIC_H
#define MUSIC_H

#include <QtQuick/QQuickPaintedItem>

class Music : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(Music)
public:
    explicit Music(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Music() override;
};

#endif // MUSIC_H
