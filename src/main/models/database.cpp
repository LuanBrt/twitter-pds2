#include "models/database.hpp"

#include <iostream>
#include <sstream>
#include <map>
#include <string>

Database::Database() {
    sqlite3_open(getenv("DBNAME"), &_db);
}

Database::~Database() {
    sqlite3_close(_db);
}   

void Database::createDb() {
    std::map<std::string, std::string> userTable;

    userTable["id"] = "INTEGER PRIMARY KEY AUTOINCREMENT";
    userTable["username"] = "VARCHAR(100) NOT NULL";
    userTable["password"] = "VARCHAR(100) NOT NULL";
    userTable["nickname"] = "VARCHAR(100) NOT NULL";
    createTable("user", userTable);
}

void Database::createTable(std::string tableName, std::map<std::string, std::string> attributes) {
    char *zErrMsg = 0;
    int rc;
    std::string sql = "CREATE TABLE " + tableName + "(";

    for (auto attr : attributes) {
        sql += attr.first + " " + attr.second + ",";
    }
    // removendo ultima virgula
    sql.pop_back();
    sql += ");";

    // executando o comando de criação
    rc = sqlite3_exec(_db, sql.c_str(), nullptr, nullptr, &zErrMsg);
    if( rc != SQLITE_OK ){
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Table created\n";
    }

}