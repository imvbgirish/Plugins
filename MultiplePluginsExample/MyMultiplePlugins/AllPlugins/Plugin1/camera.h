#ifndef CAMERA_H
#define CAMERA_H

#include <QtQuick/QQuickPaintedItem>

class Camera : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(Camera)
public:
    explicit Camera(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Camera() override;
};

#endif // CAMERA_H
