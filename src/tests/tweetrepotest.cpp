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
    Database db;
    db.createDb();

    TweetRepo tweetRepo;
    UserRepo userRepo;
    SUBCASE("Testando adição de tweet ao banco de dados") {
        User user("luanborges", "123456", "Luan Borges");
        User ur = userRepo.addUser(user);

        Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
        Tweet tr = tweetRepo.addTweet(tweet);

        CHECK(tr.description() == tweet.description());
    }

    SUBCASE("Testando busca de todos os tweets no banco de dados") {
      User user1("userteste1", "123", "Luan Borges");
      User user2("userteste2", "123", "Luan Borges");
      User user3("userteste3", "123", "Luan Borges");

      User ur1 = userRepo.addUser(user1);
      User ur2 = userRepo.addUser(user2);
      User ur3 = userRepo.addUser(user3);

      Tweet tweet1(ur1.id(), "teste tweet 1", "22/11/2023", 0);
      Tweet tweet2(ur1.id(), "teste tweet 2", "22/11/2023", 0);
      Tweet tweet3(ur3.id(), "teste tweet 3", "22/11/2023", 0);
      tweetRepo.addTweet(tweet1);
      tweetRepo.addTweet(tweet2);
      tweetRepo.addTweet(tweet3);

      std::vector<Tweet> tweetVector = tweetRepo.getTweets();

      CHECK(tweetVector[0].description() == tweet1.description());
      CHECK(tweetVector[1].description() == tweet2.description());
      CHECK(tweetVector[2].description() == tweet3.description());
    }

    SUBCASE("Testando busca de tweet por id")  {
      User user("luanborges", "123456", "Luan Borges");

      User ur = userRepo.addUser(user);

      Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
      Tweet tr = tweetRepo.addTweet(tweet);

      Tweet tweetSearch = tweetRepo.searchTweetById(tr.id());

      CHECK_EQ(tweetSearch.description(), tr.description());
    }
    remove(dbname);
}