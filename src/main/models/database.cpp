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

    std::string sqlUser = "CREATE TABLE user(id INTEGER PRIMARY KEY AUTOINCREMENT,nickname VARCHAR(100) NOT NULL,";
    sqlUser += " password VARCHAR(100) NOT NULL,username VARCHAR(100) NOT NULL);";

    std::string sqlTweet = "CREATE TABLE tweet(id INTEGER PRIMARY KEY AUTOINCREMENT, author_id INTEGER NOT NULL,";
    sqlTweet += " description VARCHAR(500) NOT NULL, timestamp VARCHAR(100) NOT NULL, likes INTEGER NOT NULL, FOREIGN KEY(author_id) REFERENCES user(id));";


    createTable("user", sqlUser);
    createTable("tweet", sqlTweet);
}

void Database::createTable(std::string tableName, std::string sql) {
    char *zErrMsg = 0;
    int rc;

    // executando o comando de criação
    rc = sqlite3_exec(_db, sql.c_str(), nullptr, nullptr, &zErrMsg);
    if( rc != SQLITE_OK ){
        std::cout << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Table created\n";
    }

}