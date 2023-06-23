#ifndef EX_FUNCS_H
#define EX_FUNCS_H

#include <QStringList>
#include <QTcpSocket>
#include <QVector>
#include <QString>
#include <QMap>
#include <QTcpSocket>

QVector<QMap<QString, Qstring>> logins;
QString move0;
QString move1;
QString move2;
QString move3;
QString move4;

void login(QString log);
void move(QTcpSocket* socket, QString cl_move);
void socket_break(QTcpSocket* socket);
void parse(QTcpSocket* sock, QString res);

#endif // EX_FUNCS_H
