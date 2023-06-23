#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>
#include <QVector>
#include "singl.h"


class Database : public Singleton<Database>
{
    friend class Singleton<Database>;
private:
    Database();
    Database(const Database&) = delete;
    Database& operator = (Database&) = delete;
    QSqlDatabase db;
    ~Database();

    void create_db();
    void db_req(QString req);
};

#endif // DATABASE_H
