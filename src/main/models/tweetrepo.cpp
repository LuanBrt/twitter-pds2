#include "models/tweetrepo.hpp"

#include <iostream>
#include <cctype>
#include <algorithm>

namespace repo {
    model::Tweet TweetRepo::addTweet(model::Tweet tweet) {
        std::string sql;
        sql += "INSERT INTO tweet (author_id, description, timestamp, likes) VALUES (";
        sql += "" + std::to_string(tweet.author().id()) + ", ";
        sql += "'" + tweet.description() + "', ";
        sql += "'" + tweet.timestamp() + "', ";
        sql += "" + std::to_string(tweet.likes()) + ");";

        int r = executeInsert(_db, sql);

        
        if (r != 0) {
            sqlite3_int64 lastRowId = sqlite3_last_insert_rowid(_db);

            // Você pode agora buscar o tweet recém-criado usando o ID obtido
            model::Tweet newTweet = searchTweetById(static_cast<int>(lastRowId));

            // Retornando o tweet recém-criado
            return newTweet;
        }

        throw "Tweet não foi adicionado ao banco de dados";
    }

    std::vector<model::Tweet> TweetRepo::getTweets() {
    std::vector<model::Tweet> tweetVec;
    std::string sql;
    sql += "SELECT * FROM tweet;";
    std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
    for (auto tweetData : result) {
        model::Tweet t(stoi(tweetData["id"]),stoi(tweetData["author_id"]), tweetData["description"], tweetData["timestamp"], stoi(tweetData["likes"]));
        tweetVec.push_back(t);
    }

    return tweetVec;
    }

    model::Tweet TweetRepo::searchTweetById(int id) {
        std::string sql;
        sql += "SELECT * FROM tweet WHERE id = " + std::to_string(id) + ";";
        std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
        
        model::Tweet t(stoi(result[0]["id"]), stoi(result[0]["author_id"]), result[0]["description"], result[0]["timestamp"], stoi(result[0]["likes"]));
        return t;
    }

    void TweetRepo::likeTweet(int id) {
        std::string sql;
        sql += "UPDATE tweet SET likes = likes + 1 WHERE id = " + std::to_string(id) + ";";

        int r = executeInsert(_db, sql);
        std::cout << r << std::endl;
    }

    void TweetRepo::dislikeTweet(int id) {
        std::string sql;
        sql += "UPDATE tweet SET likes = likes - 1 WHERE id = " + std::to_string(id) + ";";

        int r = executeInsert(_db, sql);
        std::cout << r << std::endl;
    }

    std::vector<model::Tweet> TweetRepo::getUserTimeline(model::User u) {
        std::vector<model::Tweet> response;

        std::string sql = "SELECT t.* FROM follow f JOIN tweet t ON f.followed_id = t.author_id WHERE f.follower_id="+std::to_string(u.id())+" UNION "
                            "SELECT t.* FROM tweet t WHERE t.author_id="+std::to_string(u.id())+";";
        
        std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);

        for (auto tweetData : result) {
            response.push_back(model::Tweet(stoi(tweetData["id"]), stoi(tweetData["author_id"]), tweetData["description"], tweetData["timestamp"], stoi(tweetData["likes"])));
        }

        return response;
    }

    std::vector<model::Tweet> TweetRepo::searchTweets(std::string searchString) {
        // tolower na string de busca
        std::transform(searchString.begin(), searchString.end(), searchString.begin(), ::tolower);

        // criando um vetor para armazenar os tweets com a palavra chave
        std::vector<model::Tweet> matchingTweets;

        // consulta SQL para buscar tweets no banco de dados
        std::string sql = "SELECT DISTINCT * FROM tweet WHERE LOWER(description) LIKE '%" + searchString + "%';";

        std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);

        // adicionando os tweets com a palavra chave ao vetor 
        for (auto tweetData : result) {
            matchingTweets.push_back(model::Tweet(
                stoi(tweetData["id"]),
                stoi(tweetData["author_id"]),
                tweetData["description"],
                tweetData["timestamp"],
                stoi(tweetData["likes"])
            ));
        }

        return matchingTweets;
    }
}