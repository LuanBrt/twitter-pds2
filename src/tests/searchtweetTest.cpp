#include <iostream>
#include <cstdio>
#include <string>

#include "doctest.h"
#include "models/database.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"

TEST_CASE("Testando busca de tweets no banco de dados") {
    const char* dbname = "databasetest.db";
    setenv("DBNAME", dbname, 0);
    Database db;
    db.createDb();

    TweetRepo tweetRepo;
    UserRepo userRepo;

    SUBCASE("Busca por tweets com uma palavra-chave existente") {
        User user("luanborges", "123456", "Luan Borges");
        User ur = userRepo.addUser(user);

        // adicionando tweets ao banco de dados de teste
        Tweet tweet1(ur.id(), "Meu teste de busca", "22/11/2023", 0);
        Tweet tweet2(ur.id(), "Outro teste para busca", "23/11/2023", 0);
        Tweet tweet3(ur.id(), "Mais um exemplo de busca", "24/11/2023", 0);
        tweetRepo.addTweet(tweet1);
        tweetRepo.addTweet(tweet2);
        tweetRepo.addTweet(tweet3);

        // buscando tweets com a palavra-chave "busca"
        std::vector<Tweet> result = tweetRepo.searchTweets("busca");

        // verificando se os tweets com a palavra-chave foram encontrados
        CHECK(result.size() == 3); // 3 resultados esperados
        CHECK(result[0].description() == tweet1.description());
        CHECK(result[1].description() == tweet2.description());
        CHECK(result[2].description() == tweet3.description());
    }

    SUBCASE("Busca por tweets com uma palavra-chave inexistente") {
        User user("luanborges", "123456", "Luan Borges");
        User ur = userRepo.addUser(user);

        // adicionando tweets ao banco de dados de teste
        Tweet tweet1(ur.id(), "Meu teste de busca", "22/11/2023", 0);
        Tweet tweet2(ur.id(), "Outro teste para busca", "23/11/2023", 0);
        Tweet tweet3(ur.id(), "Mais um exemplo de busca", "24/11/2023", 0);
        tweetRepo.addTweet(tweet1);
        tweetRepo.addTweet(tweet2);
        tweetRepo.addTweet(tweet3);

        // buscando tweets com a palavra-chave inexistente "inexistente"
        std::vector<Tweet> result = tweetRepo.searchTweets("inexistente");

        // verificando se nenhum tweet foi encontrado
        CHECK(result.empty()); // nenhum resultado esperado
    }

    remove(dbname);
}

