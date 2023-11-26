#include "models/tweetrepo.hpp"

#include <iostream>

Tweet TweetRepo::addTweet(Tweet tweet) {
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
        Tweet newTweet = searchTweetById(static_cast<int>(lastRowId));

        // Retornando o tweet recém-criado
        return newTweet;
    }

    throw "Tweet não foi adicionado ao banco de dados";
}

std::vector<Tweet> TweetRepo::getTweets() {
  std::vector<Tweet> tweetVec;
  std::string sql;
  sql += "SELECT * FROM tweet;";
  std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
  for (auto tweetData : result) {
      Tweet t(stoi(tweetData["id"]),stoi(tweetData["author_id"]), tweetData["description"], tweetData["timestamp"], stoi(tweetData["likes"]));
      tweetVec.push_back(t);
  }

  return tweetVec;
}

Tweet TweetRepo::searchTweetById(int id) {
    std::string sql;
    sql += "SELECT * FROM tweet WHERE id = " + std::to_string(id) + ";";
    std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
    
    Tweet t(stoi(result[0]["id"]), stoi(result[0]["author_id"]), result[0]["description"], result[0]["timestamp"], stoi(result[0]["likes"]));
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

std::vector<Tweet> TweetRepo::getUserTimeline(User u) {
    std::vector<Tweet> response;

    std::string sql = "SELECT t.* FROM follow f JOIN tweet t ON f.followed_id = t.author_id WHERE f.follower_id="+std::to_string(u.id())+" UNION "
                        "SELECT t.* FROM tweet t WHERE t.author_id="+std::to_string(u.id())+";";
    
    std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);

    for (auto tweetData : result) {
        response.push_back(Tweet(stoi(tweetData["id"]), stoi(tweetData["author_id"]), tweetData["description"], tweetData["timestamp"], stoi(tweetData["likes"])));
    }

    return response;
}
