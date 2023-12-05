#include <iostream>
#include <cstdio>
#include <string>

#include "doctest.h"
#include "models/database.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"
#include "models/comment.hpp"
#include "models/commentrepo.hpp"

TEST_CASE("Testando repositorio de usuários") {
    const char *dbname = "databasetest.db";
    setenv("DBNAME", dbname, 0);
    repo::Database db;
    db.createDb();

    repo::TweetRepo tweetRepo;
    repo::UserRepo userRepo;
    repo::CommentRepo commentRepo;
    SUBCASE("Testando adição de tweet ao banco de dados") {
        model::User user("luanborges", "123456", "Luan Borges");
        model::User ur = userRepo.addUser(user);

        model::Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
        model::Tweet tr = tweetRepo.addTweet(tweet);

        model::Comment comment(ur.id(), tr.id(), "teste comentário");
        model::Comment cr = commentRepo.addComment(comment);

        CHECK(cr.description() == comment.description());
    }

    SUBCASE("Testando busca de todos os tweets no banco de dados") {
      model::User user("luanborges", "123456", "Luan Borges");
      model::User ur = userRepo.addUser(user);

      model::Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
      model::Tweet tr = tweetRepo.addTweet(tweet);

      model::Comment comment1(ur.id(), tr.id(), "teste comentário 1");
      model::Comment comment2(ur.id(), tr.id(), "teste comentário 2");
      model::Comment comment3(ur.id(), tr.id(), "teste comentário 3");
        
      commentRepo.addComment(comment1);
      commentRepo.addComment(comment2);
      commentRepo.addComment(comment3);

      std::vector<model::Comment> commentVector = commentRepo.getCommentsByTweetId(tr.id());

      CHECK(commentVector[0].description() == comment1.description());
      CHECK(commentVector[1].description() == comment2.description());
      CHECK(commentVector[2].description() == comment3.description());
    }

    SUBCASE("Testando busca de tweet por id")  {
      model::User user("luanborges", "123456", "Luan Borges");

      model::User ur = userRepo.addUser(user);

      model::Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
      model::Tweet tr = tweetRepo.addTweet(tweet);

      model::Comment comment(ur.id(), tr.id(), "teste comentário");
      model::Comment cr = commentRepo.addComment(comment);

      model::Comment commentSearch = commentRepo.searchCommentById(cr.id());

      CHECK_EQ(commentSearch.description(), cr.description());
    }
    remove(dbname);
}