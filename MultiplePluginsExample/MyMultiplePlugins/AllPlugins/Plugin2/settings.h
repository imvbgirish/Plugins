#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtQuick/QQuickPaintedItem>

class Settings : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(Settings)
public:
    explicit Settings(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Settings() override;
};

#endif // SETTINGS_H
