#ifndef GIRISH_H
#define GIRISH_H

#include <QtQuick/QQuickPaintedItem>

class Girish : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL)
    QML_ELEMENT
    Q_DISABLE_COPY(Girish)
public:
    explicit Girish(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Girish() override;

    QString getName() const;
    void setName(const QString &newName);

    Q_INVOKABLE void display();

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // GIRISH_H
