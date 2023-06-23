#include "ex_funcs.h"
#include "database.h"
#include "mytcpserver_ex.h"

void login(QString res){
    if (five_logins() == 0){
        QString login = QString.split("&")[1];
        QSq
    }
}

void socket_break(QTcpSocket* socket){
    QVector<QString> new_logins;
    delete number = sock_num(socket);
    for (int i = 0; i < logins.size() - 1; i++){
        if (i == number)
            continue;
        new_logins.append(logins[i]);
    }
    logins = new_logins;
    socket->close();
}

void parse(QTcpSocket* sock, QString req){
    QStringList reqs = req.split("&");
    int descriptor = data[0].toInt();
    if (req[1] == "start"){
        login(req[2]);
    } else if (req[1] == "break"){
        socket_break(sock);
    } else if (req[1] == "stats"){
        for (int i = 0; i < logins.size(); i++)
            sock->write(login[i].toUtf8() + '\n');
    } else if (req[1] == "choice"){
        move(sock, req[2]);
    }
}

void move(QTcpSocket* socket, QString cl_move){
    if (sock_num(socket) == 0){
        move0 = cl_move;
    } else if (sock_num(socket) == 1){
        move1 = cl_move;
    } else if (sock_num(socket) == 2){
        move2 = cl_move;
    } else if (sock_num(socket) == 3){
        move3 = cl_move;
    } else if (sock_num(socket) == 4){
        move4 = cl_move;
    }
    if (move0, move1, move2, move3, move4){
        QVector<int> moves;
        moves.append(move0);
        moves.append(move1);
        moves.append(move2);
        moves.append(move3);
        moves.append(move4);
        int maxi = -10000;
        for (int i = 0; i < 5; i++)
            if (QString.number(moves[i]) > maxi)
                maxi = QString.number(moves[i]);
        if (QString.number(move0) = maxi){

        } else if (QString.number(move1) = maxi){

        } else if (QString.number(move2) = maxi){

        } else if (QString.number(move3) = maxi){

        } else if (QString.number(move4) = maxi){

        }
        win_nick = logins[sock_num(socket)];
        QString db_req = "Select client_name"
                         "where client_name = " + win_nick;
    }
}
