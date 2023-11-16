#include "models/userrepo.hpp"

#include <iostream>

int UserRepo::addUser(User user) {
    std::string sql;
    sql += "INSERT INTO user (username, password, nickname) VALUES (";
    sql += "'" + user.username() + "', ";
    sql += "'" + user.password() + "', ";
    sql += "'" + user.nickname() + "');";
    int r = executeInsert(_db, sql);

    return r;
}
std::vector<User> UserRepo::searchUser(std::string keyword) {
    std::vector<User> userVec;
    std::string sql;
    sql += "SELECT * FROM user WHERE username LIKE '%" + keyword + "%' LIMIT 5;";
    std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
    for (auto userData : result) {
        User u(userData["username"], userData["password"], userData["nickname"]);
        userVec.push_back(u);
    }

    return userVec;
}
