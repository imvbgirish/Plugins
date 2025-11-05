#include "myitem.h"

#include <QPainter>

MyItem::MyItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

void MyItem::paint(QPainter *painter)
{
    QPen pen(QColorConstants::Red, 2);
    QBrush brush(QColorConstants::Red);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(0, 0, 100, 100);
}

MyItem::~MyItem() {}

QString MyItem::getName() const
{
    qDebug() << Q_FUNC_INFO;
    return m_name;
}

void MyItem::setName(const QString &newName)
{
    qDebug() << Q_FUNC_INFO;
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

void MyItem::display()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "Hey I am " << getName() ;
}
