#ifndef GREETER_H
#define GREETER_H

#include <QtQuick/QQuickPaintedItem>

class Greeter : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL)
    Q_DISABLE_COPY(Greeter)
public:
    explicit Greeter(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~Greeter() override;

    QString getName() const;
    void setName(const QString &newName);

    Q_INVOKABLE void display();

signals:
    void nameChanged();

private:
    QString m_name;
};

#endif // GREETER_H
