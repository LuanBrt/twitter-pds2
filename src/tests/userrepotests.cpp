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
        int r = repo.addUser(user);
        CHECK(r == 1);
    }

    SUBCASE("Testando busca de usuario ao banco de dados") {
        User user1("userfind1", "123456", "Luan Borges");
        User user2("userfind2", "123456", "Luan Borges");
        User user3("userfind3", "123456", "Luan Borges");

        int r1 = repo.addUser(user1);
        CHECK(r1 == 1);
        int r2 = repo.addUser(user2);
        CHECK(r2 == 1);
        int r3 = repo.addUser(user3);
        CHECK(r3 == 1);

        std::vector<User> r = repo.searchUser("userfind");
        CHECK(r.size() == 3);
    }
    remove(dbname);

}