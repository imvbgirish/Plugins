#include "settings.h"

#include <QPainter>

Settings::Settings(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

void Settings::paint(QPainter *painter)
{
    QPen pen(QColorConstants::Black, 2);
    QBrush brush(QColorConstants::Black);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(100, 100, 100, 100);
}

Settings::~Settings() {}
