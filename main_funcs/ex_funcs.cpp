#include "ex_funcs.h"
#include "database.h"
#include "mytcpserver_ex.h"

void login(QString res){
    if (MyTcpServer::get_instance()->five_logins() == 0){
        QString login = res.split("&")[1];
        QString dab_req;
        dab_req = "insert into clients "
              "values ('" + res + "');";
        Database::get_instance()->db_req(dab_req);
    }
}

void socket_break(QTcpSocket* socket){
    QVector<QString> new_logins;
    int number = MyTcpServer::get_instance()->sock_num(socket);
    for (int i = 0; i < logins.size() - 1; i++){
        if (i == number)
            continue;
        new_logins.append(logins[i]);
    }
    logins = new_logins;
    socket->close();
}

void move(QTcpSocket* socket, QString cl_move){
    if (MyTcpServer::get_instance()->sock_num(socket) == 0){
        move0 = cl_move;
    } else if (MyTcpServer::get_instance()->sock_num(socket) == 1){
        move1 = cl_move;
    } else if (MyTcpServer::get_instance()->sock_num(socket) == 2){
        move2 = cl_move;
    } else if (MyTcpServer::get_instance()->sock_num(socket) == 3){
        move3 = cl_move;
    } else if (MyTcpServer::get_instance()->sock_num(socket) == 4){
        move4 = cl_move;
    }
    if (move0 != "" && move1 != "" && move2 != "" && move3 != "" && move4 != ""){
        QVector<int> moves;
        moves.append(move0.toInt());
        moves.append(move1.toInt());
        moves.append(move2.toInt());
        moves.append(move3.toInt());
        moves.append(move4.toInt());
        int maxi = -10000;
        int winner_num;
        for (int i = 0; i < 5; i++)
            if (moves[i] > maxi)
                maxi = moves[i];
        if (move0.toInt() == maxi){
            winner_num = 0;
        } else if (move1.toInt() == maxi){
            winner_num = 1;
        } else if (move2.toInt() == maxi){
            winner_num = 2;
        } else if (move3.toInt() == maxi){
            winner_num = 3;
        } else if (move4.toInt() == maxi){
            winner_num = 4;
        }
        QVector<QString> losers;
        for (int i = 0; i < logins.size(); i++){
            if (i == winner_num)
                continue;
            losers.append(logins[i]);
        }
        QString dab_req = "Update clients "
                         "set wins = wins + 1 "
                         "where client_name = " + logins[winner_num];
        Database::get_instance()->db_req(dab_req);
        for (int i = 0; i < losers.size; i++){
            QString dab_req = "Update clients "
                             "set loses = loses + 1 "
                             "where client_name = " + losers[i];
            Database::get_instance()->db_req(dab_req);
        }
        MyTcpServer::get_instance()->los_win_m(winner_num);
    }
}

void parse(QTcpSocket* sock, QString req){
    QList reqs = req.split("&");
    int descriptor = QString(req[0]).toInt();
    if (req[1] == QString("start")){
        login(req[2]);
        sock->write(QString("waiting").toUtf8() + '\n');
    } else if (req[1] == QString("break")){
        socket_break(sock);
    } else if (req[1] == QString("stats")){
        for (int i = 0; i < logins.size(); i++)
            sock->write(logins[i].toUtf8() + '\n');
    } else if (req[1] == QString("choice")){
        move(sock, req[2]);
    }
}
