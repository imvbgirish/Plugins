#include "chrome.h"

#include <QPainter>

Chrome::Chrome(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

void Chrome::paint(QPainter *painter)
{
    QPen pen(QColorConstants::DarkGreen, 2);
    QBrush brush(QColorConstants::DarkGreen);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(100, 100, 100, 100);
}

Chrome::~Chrome() {}
