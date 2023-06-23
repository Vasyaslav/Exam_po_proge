#include "database.h"

Database::Database(){
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("examdb.sqlite");
    this->create_db();
}

Database::create_db(){
    QSqlQuery query(this->db);

    query.exec("Create table clients("
               "id integer PRIMARY KEY,"
               "client_name varchar(64) not null"
               "wins integer default 0"
               "loses integer default 0)");
}

Database::~Database(){
    db.close();
}

Database::db_req (QString req){
    QSqlQuery query(this->db);
    query.exec(req);
}
