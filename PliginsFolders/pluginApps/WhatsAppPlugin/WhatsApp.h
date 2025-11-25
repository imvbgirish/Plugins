#ifndef WHATSAPP_H
#define WHATSAPP_H

#include <QObject>

class WhatsApp : public QObject
{
    Q_OBJECT
public:
    explicit WhatsApp(QObject *parent = nullptr);

signals:
};

#endif // WHATSAPP_H
