#include "TcpSocket.h"

TcpSocket::TcpSocket(qintptr handle, QObject * parent) :
    QTcpSocket(parent)
{
    setSocketDescriptor(handle);

    connect(this, &TcpSocket::readyRead, [&](){
        emit dataIncoming(this);
    });

    connect(this, &TcpSocket::stateChanged, [&](int state){
       emit socketStateChanged(this, state);
    });
}
