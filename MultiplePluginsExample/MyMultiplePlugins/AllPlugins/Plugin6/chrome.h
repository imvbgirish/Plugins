#ifndef CHROME_H
#define CHROME_H

#include <QtQuick/QQuickPaintedItem>

class Chrome : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(Chrome)
public:
    explicit Chrome(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Chrome() override;
};

#endif // CHROME_H
