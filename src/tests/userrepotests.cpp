#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <cstdio>

#include "doctest.h"
#include "models/database.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"

TEST_CASE("Testando repositorio de usuários") {
    const char *dbname = "databasetest.db";
    setenv("DBNAME", dbname, 0);
    repo::Database db;
    db.createDb();

    repo::UserRepo repo;
    SUBCASE("Testando adição de usuario ao banco de dados") {
        model::User user("luanborges", "123456", "Luan Borges");
        model::User ur = repo.addUser(user);
        CHECK(ur.username() == user.username());
    }

    SUBCASE("Testando busca de usuario ao banco de dados") {
        model::User user1("userfind1", "123456", "Luan Borges");
        model::User user2("userfind2", "123456", "Luan Borges");
        model::User user3("userfind3", "123456", "Luan Borges");

        model::User ur1 = repo.addUser(user1);
        CHECK(ur1.username() == user1.username());
        model::User ur2 = repo.addUser(user2);
        CHECK(ur2.username() == user2.username());
        model::User ur3 = repo.addUser(user3);
        CHECK(ur3.username() == user3.username());

        std::vector<model::User> r = repo.searchUser("userfind");
        CHECK(r.size() == 3);
    }

    SUBCASE("Testando seguir um usuario") {
        model::User user1("talvani", "123456", "Talvani");
        model::User ur1 = repo.addUser(user1);

        model::User user2("luan", "123456", "Luan Borges");
        model::User ur2 = repo.addUser(user2);

        repo.followUser(ur1, ur2);
        std::vector<model::User> following = repo.getFollowing(ur1);
        CHECK(following.size() == 1);
        CHECK(following[0].id() == ur2.id());
    }

    remove(dbname);

}