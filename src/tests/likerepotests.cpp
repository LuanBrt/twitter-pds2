#include <iostream>
#include <cstdio>
#include <string>

#include "doctest.h"
#include "models/database.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"
#include "models/likerepo.hpp"

TEST_CASE("Testando repositorio de usuários") {
    const char *dbname = "databasetest.db";
    setenv("DBNAME", dbname, 0);
    Database db;
    db.createDb();

    TweetRepo tweetRepo;
    UserRepo userRepo;
    LikeRepo likeRepo;
    SUBCASE("Testando adição e remoção de um like no repositório") {
        User user("luanborges", "123456", "Luan Borges");
        User ur = userRepo.addUser(user);

        Tweet tweet(ur.id(), "teste tweet", "22/11/2023", 0);
        Tweet tr = tweetRepo.addTweet(tweet);

        likeRepo.addLike(ur.id(), tr.id());

        CHECK_EQ(likeRepo.searchLikeByUserId(ur.id(), tr.id()), 1);
        
        likeRepo.deleteLike(ur.id(), tr.id());

        CHECK_EQ(likeRepo.searchLikeByUserId(ur.id(), tr.id()), 0);
    }

    remove(dbname);
}