#include "models/userrepo.hpp"

#include <iostream>

namespace repo {
    model::User UserRepo::addUser(model::User user) {
        std::string sql;
        sql += "INSERT INTO user (username, password, nickname) VALUES (";
        sql += "'" + user.username() + "', ";
        sql += "'" + user.password() + "', ";
        sql += "'" + user.nickname() + "');";
        int r = executeInsert(_db, sql);

        if (r != 0) {
            sqlite3_int64 lastRowId = sqlite3_last_insert_rowid(_db);

            // Você pode agora buscar o usuário recém-criado usando o ID obtido
            model::User newUser = searchUserById(static_cast<int>(lastRowId));

            // Retornando o usuário recém-criado
            return newUser;
        }

        throw "Usuário não foi adicionado ao banco de dados";
    }

    model::User UserRepo::searchUserById(int id) {
        std::string sql;
        sql += "SELECT * FROM user WHERE id = " + std::to_string(id) + ";";
        std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
        
        model::User u(stoi(result[0]["id"]), result[0]["username"], result[0]["password"], result[0]["nickname"]);
        return u;
    }

    // FUNÇÃO QUE BUSCA O USUÁRIO NO BANCO DE DADOS PELO NOME
    std::vector<model::User> UserRepo::searchUser(std::string keyword) {
        std::vector<model::User> userVec;
        std::string sql;
        sql += "SELECT * FROM user WHERE username LIKE '%" + keyword + "%' LIMIT 5;";
        std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
        for (auto userData : result) {
            model::User u(stoi(userData["id"]), userData["username"], userData["password"], userData["nickname"]);
            userVec.push_back(u);
        } 

        return userVec;
    }

    std::vector<model::User> UserRepo::getFollowing(model::User u) {
        std::vector<model::User> userVec;
        std::string sql = "SELECT u.id FROM follow f JOIN user u ON u.id = f.followed_id WHERE follower_id="+std::to_string(u.id())+";";
        std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
        for (auto userId : result) {
            
            userVec.push_back(searchUserById(stoi(userId["id"])));
        }

        return userVec;
    }

    model::User UserRepo::followUser(model::User follower, model::User followed) {
        std::string sql = "INSERT INTO follow (follower_id, followed_id) VALUES ("+std::to_string(follower.id())+", "+std::to_string(followed.id())+");";
        int r = executeInsert(_db, sql);
        return followed;
    }
}