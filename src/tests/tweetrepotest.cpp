#include <iostream>
#include <cstdio>
#include <string>

#include "doctest.h"
#include "models/database.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"

TEST_CASE("Testando repositorio de usuários") {
    const char *dbname = "databasetest.db";
    setenv("DBNAME", dbname, 0);
    repo::Database db;
    db.createDb();

    repo::TweetRepo tweetRepo;
    repo::UserRepo userRepo;
    SUBCASE("Testando adição de tweet ao banco de dados") {
        model::User user("luanborges", "123456", "Luan Borges");
        model::User ur = userRepo.addUser(user);

        model::Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
        model::Tweet tr = tweetRepo.addTweet(tweet);

        CHECK(tr.description() == tweet.description());
    }

    SUBCASE("Testando busca de todos os tweets no banco de dados") {
      model::User user1("userteste1", "123", "Luan Borges");
      model::User user2("userteste2", "123", "Luan Borges");
      model::User user3("userteste3", "123", "Luan Borges");

      model::User ur1 = userRepo.addUser(user1);
      model::User ur2 = userRepo.addUser(user2);
      model::User ur3 = userRepo.addUser(user3);

      model::Tweet tweet1(ur1.id(), "teste tweet 1", "22/11/2023", 0);
      model::Tweet tweet2(ur1.id(), "teste tweet 2", "22/11/2023", 0);
      model::Tweet tweet3(ur3.id(), "teste tweet 3", "22/11/2023", 0);
      tweetRepo.addTweet(tweet1);
      tweetRepo.addTweet(tweet2);
      tweetRepo.addTweet(tweet3);

      std::vector<model::Tweet> tweetVector = tweetRepo.getTweets();

      CHECK(tweetVector[0].description() == tweet1.description());
      CHECK(tweetVector[1].description() == tweet2.description());
      CHECK(tweetVector[2].description() == tweet3.description());
    }

    SUBCASE("Testando busca de tweet por id")  {
      model::User user("luanborges", "123456", "Luan Borges");

      model::User ur = userRepo.addUser(user);

      model::Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
      model::Tweet tr = tweetRepo.addTweet(tweet);

      model::Tweet tweetSearch = tweetRepo.searchTweetById(tr.id());

      CHECK_EQ(tweetSearch.description(), tr.description());
    }

    SUBCASE("Testando obtenção de timeline de usuário") {

      // criando usuários
      model::User user1("talvani", "123456", "Talvani");
      model::User ur1 = userRepo.addUser(user1);
      model::User user2("luan", "123456", "Luan Borges");
      model::User ur2 = userRepo.addUser(user2);

      // seguindo usuário
      userRepo.followUser(ur1, ur2);

      // criando tweet
      model::Tweet tweet(ur2.id(), "teste tweet", "24/11/2023", 0);
      model::Tweet tr = tweetRepo.addTweet(tweet);


      std::vector<model::Tweet> timeline = tweetRepo.getUserTimeline(ur1);
      CHECK(timeline[0].id() == tr.id());

    }

    remove(dbname);
}