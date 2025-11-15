#include "maps.h"

#include <QPainter>

Maps::Maps(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

void Maps::paint(QPainter *painter)
{
    QPen pen(QColorConstants::Yellow, 2);
    QBrush brush(QColorConstants::Yellow);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(100, 100, 100, 100);
}

Maps::~Maps() {}
