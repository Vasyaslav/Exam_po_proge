#ifndef MYSERVER_H
#define MYSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QCoreApplication>
#include <QStringList>
#include <QByteArray>
#include <Qvector>
#include "singl.h"
#include <QList>

class MyTcpServer : public QObject, public Singleton<MyTcpServer>
{
    friend class Singleton<MyTcpServer>;
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();
    int five_logins();
    int sock_num(QTcpSocket* sock);
    QVector<QTcpSocket*> mTcpSocket;
public slots:
    void slotNewConnection();
    void slotClientDisconnected();
    void los_win_m(int winner);

    void slotServerRead();
    //void slotReadClient();
private:
    MyTcpServer(const MyTcpServer&) = delete;
    MyTcpServer& operator = (MyTcpServer&) = delete;
    QTcpServer * mTcpServer;
    int server_status;
};
#endif // MYSERVER_H







