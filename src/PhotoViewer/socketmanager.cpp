#include "socketmanager.h"
#include "TcpSocket.h"
#include <QTextStream>

SocketManager::SocketManager(QObject * parent) :
    QTcpServer(parent),
    clientSocket(nullptr)
{

}

bool SocketManager::startServer(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

bool SocketManager::sendMsg(const QString text)
{
    if(clientSocket != nullptr){
        QTextStream T(clientSocket);
        T << text;
        clientSocket->flush();
        return true;
    }else{
        return false;
    }
}

void SocketManager::incomingConnection(qintptr handle)
{
    clientSocket = new TcpSocket(handle, this);

    emit newClientConnected();

    printf("TESTING");

    connect(clientSocket, &TcpSocket::dataIncoming, [&](TcpSocket *S){
        QTextStream T(S);
        emit receivingData(T.readAll().toUtf8());
    });

    connect(clientSocket, &TcpSocket::socketStateChanged, [&](TcpSocket *socket, int state){
        if(state == TcpSocket::UnconnectedState) emit closeAll();
    });
}
