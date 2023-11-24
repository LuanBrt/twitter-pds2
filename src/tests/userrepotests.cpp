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
    Database db;
    db.createDb();

    UserRepo repo;
    SUBCASE("Testando adição de usuario ao banco de dados") {
        User user("luanborges", "123456", "Luan Borges");
        User ur = repo.addUser(user);
        CHECK(ur.username() == user.username());
    }

    SUBCASE("Testando busca de usuario ao banco de dados") {
        User user1("userfind1", "123456", "Luan Borges");
        User user2("userfind2", "123456", "Luan Borges");
        User user3("userfind3", "123456", "Luan Borges");

        User ur1 = repo.addUser(user1);
        CHECK(ur1.username() == user1.username());
        User ur2 = repo.addUser(user2);
        CHECK(ur2.username() == user2.username());
        User ur3 = repo.addUser(user3);
        CHECK(ur3.username() == user3.username());

        std::vector<User> r = repo.searchUser("userfind");
        CHECK(r.size() == 3);
    }
    remove(dbname);

}