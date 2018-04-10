#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket(qintptr handle, QObject * parent = 0);

signals:
    void dataIncoming(TcpSocket *);
    void socketStateChanged(TcpSocket *, int);
};

#endif // TCPSOCKET_H
