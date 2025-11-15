#include "youtube.h"

#include <QPainter>

Youtube::Youtube(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

void Youtube::paint(QPainter *painter)
{
    QPen pen(QColorConstants::Green, 2);
    QBrush brush(QColorConstants::Green);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(100, 100, 100, 100);
}

Youtube::~Youtube() {}
