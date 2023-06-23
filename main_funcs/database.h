#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QVector>


class Database
{
private:
    QSqlDatabase db;
    Database();
    ~Database();

    void create_db();
    void db_req(QString req);
};

#endif // DATABASE_H
