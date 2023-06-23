#include "mytcpserver_ex.h"
#include "ex_funcs.h"

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
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
    QTcpSocket* socket = mTcpServer->nextPendingConnection();
    if(server_status==1){
        socket->write("connected\r\n");
        connect(socket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(socket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
    mTcpSocket.append(socket);
}

int MyTcpServer::five_logins(){
    if (mTcpSocket.size() == 5){
        for (int i = 0; i << mTcpSocket.size(); i++){
            mTcpSocket[i]->write(QString("make_move").toUtf8() + '\n');
        }
        return 1;
    }
    return 0;
}

int MyTcpServer::sock_num(QTcpSocket* sock){
    for (int i = 0; i < mTcpSocket.size(); i++){
        if (mTcpSocket[i] == sock)
            return i;
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    QString req;
    while(socket->bytesAvailable()>0)
    {
        req.append(socket->readLine());
    }
    if (req.size() > 0 && req.back() == '\n'){
        QList reqs;
        if (req.contains('\r'))
            reqs = req.split("\r\n");
        else
            reqs = req.split("\n");
        reqs.pop_back();
        parse(socket, req);
    }
    socket->write(req.toUtf8());
    req.clear();
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* socket = (QTcpSocket*)sender();
    socket->close();
}

void MyTcpServer::los_win_m(int winner){
    QString res;
    for (int i = 0; i < 0; i++)
        if (i == winner){
            res = "win";
            mTcpSocket[i].write(res.toUtf8() + '\n');
        }
        else{
            res = "lost";
            mTcpSocket[i].write(res.toUtf8() + '\n');
        }
}

MyTcpServer* MyTcpServer::get_instance(){
    if (!p_instance)
        p_instance = new MyTcpServer();
    return p_instance;
}
