#include "models/commentrepo.hpp"

#include <iostream>

namespace repo {
  model::Comment CommentRepo::addComment(model::Comment comment) {
      std::string sql;
      sql += "INSERT INTO comment (author_id, tweet_id, description) VALUES (";
      sql += "" + std::to_string(comment.author().id()) + ", ";
      sql += "" + std::to_string(comment.tweet().id()) + ", ";
      sql += "'" + comment.description() + "');";

      std::cout << sql << std::endl;
      int r = executeInsert(_db, sql);
      std::cout << r << std::endl;

      
      if (r != 0) {
          sqlite3_int64 lastRowId = sqlite3_last_insert_rowid(_db);

          // Você pode agora buscar o tweet recém-criado usando o ID obtido
          model::Comment newComment = searchCommentById(static_cast<int>(lastRowId));

          // Retornando o tweet recém-criado
          return newComment;
      }

      throw "Comment não foi adicionado ao banco de dados";
  }

  std::vector<model::Comment> CommentRepo::getCommentsByTweetId(int tweetId) {
    std::vector<model::Comment> commentVec;
    std::string sql;
    sql += "SELECT * FROM comment WHERE tweet_id = " + std::to_string(tweetId) + ";";
    std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);
    for (auto commentData : result) {
        model::Comment c(stoi(commentData["id"]), stoi(commentData["author_id"]), 
          stoi(commentData["tweet_id"]), commentData["description"]);
        commentVec.push_back(c);
    }

    return commentVec;
  }

  model::Comment CommentRepo::searchCommentById(int id) {
    std::string sql;
    sql += "SELECT * FROM comment WHERE id = " + std::to_string(id) + ";";
    std::vector<std::map<std::string, std::string>> result = executeSelect(_db, sql);

    model::Comment c(stoi(result[0]["id"]), stoi(result[0]["author_id"]), 
      stoi(result[0]["tweet_id"]), result[0]["description"]);

    return c;
  }
}