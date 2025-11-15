#ifndef MAPS_H
#define MAPS_H

#include <QtQuick/QQuickPaintedItem>

class Maps : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(Maps)
public:
    explicit Maps(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Maps() override;
};

#endif // MAPS_H
