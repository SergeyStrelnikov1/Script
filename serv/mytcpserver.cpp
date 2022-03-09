#include "mytcpserver.h"
#include <QDebug>
#include <QCoreApplication>

MyTcpServer::~MyTcpServer()
{
    mTcpServer->close();
    server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
   if(server_status == 1){
        QTcpSocket * temp = mTcpServer->nextPendingConnection();
        temp->write("Hello, World!!! I am echo server!\r\n");
        int idTemp = temp->socketDescriptor();
        mTcpSocket[idTemp] = temp;
        connect(temp, &QTcpSocket::readyRead, this, &MyTcpServer::slotServerRead);
        connect(temp, &QTcpSocket::disconnected, this, &MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* temp = (QTcpSocket*)sender();

    QString res = "";
    while(temp->bytesAvailable()>0)
    {
        QByteArray array = temp->readAll();
        res += array;
    }
    temp->write(res.toUtf8());
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* temp = (QTcpSocket*)sender();
    int idTemp = temp->socketDescriptor();
    temp->close();
    mTcpSocket.remove(idTemp);
}
