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
    Database db;
    db.createDb();

    TweetRepo tweetRepo;
    UserRepo userRepo;
    CommentRepo commentRepo;
    SUBCASE("Testando adição de tweet ao banco de dados") {
        User user("luanborges", "123456", "Luan Borges");
        User ur = userRepo.addUser(user);

        Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
        Tweet tr = tweetRepo.addTweet(tweet);

        Comment comment(ur.id(), tr.id(), "teste comentário");
        Comment cr = commentRepo.addComment(comment);

        CHECK(cr.description() == comment.description());
    }

    SUBCASE("Testando busca de todos os tweets no banco de dados") {
      User user("luanborges", "123456", "Luan Borges");
      User ur = userRepo.addUser(user);

      Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
      Tweet tr = tweetRepo.addTweet(tweet);

      Comment comment1(ur.id(), tr.id(), "teste comentário 1");
      Comment comment2(ur.id(), tr.id(), "teste comentário 2");
      Comment comment3(ur.id(), tr.id(), "teste comentário 3");
        
      commentRepo.addComment(comment1);
      commentRepo.addComment(comment2);
      commentRepo.addComment(comment3);

      std::vector<Comment> commentVector = commentRepo.getCommentsByTweetId(tr.id());

      CHECK(commentVector[0].description() == comment1.description());
      CHECK(commentVector[1].description() == comment2.description());
      CHECK(commentVector[2].description() == comment3.description());
    }

    SUBCASE("Testando busca de tweet por id")  {
      User user("luanborges", "123456", "Luan Borges");

      User ur = userRepo.addUser(user);

      Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
      Tweet tr = tweetRepo.addTweet(tweet);

      Comment comment(ur.id(), tr.id(), "teste comentário");
      Comment cr = commentRepo.addComment(comment);

      Comment commentSearch = commentRepo.searchCommentById(cr.id());

      CHECK_EQ(commentSearch.description(), cr.description());
    }
    remove(dbname);
}