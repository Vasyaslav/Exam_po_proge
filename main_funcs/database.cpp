#include "database.h"

Database::Database(){
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName("examdb.sqlite");
    this->create_db();
}

void Database::create_db(){
    QSqlQuery query(this->db);

    query.exec("Create table clients("
               "client_name varchar(64) not null primary key, "
               "wins integer default 0, "
               "loses integer default 0)");
}

Database::~Database(){
    db.close();
}

void Database::db_req (QString req){
    QSqlQuery query(this->db);
    query.exec(req);
}

Database* Database::get_instance(){
    if (!p_instance)
        p_instance = new Database();
    return p_instance;
}
