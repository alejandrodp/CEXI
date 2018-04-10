#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QTcpServer>

class QTcpSocket;
class TcpSocket;

class SocketManager : public QTcpServer
{
    Q_OBJECT
public:
    SocketManager(QObject * parent = 0);
    bool startServer(quint16 port);
    bool sendMsg(const QString text);
protected:
    void incomingConnection(qintptr handle);
signals:
    void receivingData(QByteArray);
    void closeAll();
    void newClientConnected();
private:
    TcpSocket * clientSocket;
};

#endif // SOCKETMANAGER_H
