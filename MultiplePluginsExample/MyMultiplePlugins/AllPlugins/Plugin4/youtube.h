#ifndef YOUTUBE_H
#define YOUTUBE_H

#include <QtQuick/QQuickPaintedItem>

class Youtube : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(Youtube)
public:
    explicit Youtube(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Youtube() override;
};

#endif // YOUTUBE_H
