#ifndef MYITEM_H
#define MYITEM_H

#include <QtQuick/QQuickPaintedItem>

class MyItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL)
    QML_ELEMENT
    Q_DISABLE_COPY(MyItem)
public:
    explicit MyItem(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~MyItem() override;

    QString getName() const;
    void setName(const QString &newName);

    Q_INVOKABLE void display();

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // MYITEM_H
