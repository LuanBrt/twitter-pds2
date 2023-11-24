#include "models/likerepo.hpp"

#include <iostream>

void LikeRepo::addLike(int userId, int tweetId) {
    std::string sql;
    sql += "INSERT INTO like (user_id, tweet_id) VALUES (";
    sql += "" + std::to_string(userId) + ", ";
    sql += "" + std::to_string(tweetId) + ");";

    std::cout << sql << std::endl;
    int r = executeInsert(_db, sql);
    std::cout << r << std::endl;
}

int LikeRepo::searchLikeByUserId(int userId, int tweetId) {
    std::string sql;
    sql += "SELECT * FROM like WHERE user_id = " + std::to_string(userId) + " AND "
           "tweet_id = " + std::to_string(tweetId) + ";";
    
    std::cout << sql << std::endl;
    std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);

    return result.size();
}

void LikeRepo::deleteLike(int userId, int tweetId) {
    std::string sql;
    sql += "DELETE FROM like WHERE user_id = ";
    sql += std::to_string(userId) + " AND tweet_id = ";
    sql += std::to_string(tweetId) + ";";

    std::cout << sql << std::endl;
    int r = executeInsert(_db, sql);
    std::cout << r << std::endl;
}
