#include "music.h"

#include <QPainter>

Music::Music(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

void Music::paint(QPainter *painter)
{
    QPen pen(QColorConstants::Magenta, 2);
    QBrush brush(QColorConstants::Magenta);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(100, 100, 100, 100);
}

Music::~Music() {}
