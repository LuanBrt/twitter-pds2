#include <iostream>
#include <cstdio>

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

    TweetRepo repo;
    SUBCASE("Testando adição de tweet ao banco de dados") {
        User user("luanborges", "123456", "Luan Borges");

        UserRepo _userRepo;
        User ur = _userRepo.addUser(user);

        Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
        Tweet tr = repo.addTweet(tweet);

        CHECK(tr.description() == tweet.description());
    }

    SUBCASE("Testando busca de todos os tweets no banco de dados") {
      User user1("userteste1", "123", "Luan Borges");
      User user2("userteste2", "123", "Luan Borges");
      User user3("userteste3", "123", "Luan Borges");

      UserRepo _userRepo;
      User ur1 = _userRepo.addUser(user1);
      User ur2 = _userRepo.addUser(user2);
      User ur3 = _userRepo.addUser(user3);

      Tweet tweet1(ur1.id(), "teste tweet 1", "22/11/2023", 0);
      Tweet tweet2(ur1.id(), "teste tweet 2", "22/11/2023", 0);
      Tweet tweet3(ur3.id(), "teste tweet 3", "22/11/2023", 0);
      repo.addTweet(tweet1);
      repo.addTweet(tweet2);
      repo.addTweet(tweet3);

      std::vector<Tweet> tweetVector = repo.getTweets();

      CHECK(tweetVector[1].description() == tweet1.description());
      CHECK(tweetVector[2].description() == tweet2.description());
      CHECK(tweetVector[3].description() == tweet3.description());
    }
}