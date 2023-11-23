#pragma once

#include "models/abstractrepo.hpp"
#include "models/tweet.hpp"

#include <string>
#include <vector>

class TweetRepo : public AbstractRepo {
public:

    /// @brief Adiciona um usuario ao banco de dados
    /// @param tweet 
    /// @return Retorna 1 caso sucesso e 0 caso erro
    Tweet addTweet(Tweet tweet);

    /// @brief Pega todos os tweets do banco de dados
    /// @return Retorna uma lista de todos os tweets do banco de dados
    std::vector<Tweet> getTweets();


    /// @brief Busca tweets que foram enviados por um usuario com esse username
    /// @param id
    /// @return Retorna uma lista de tweets que contenham o author como esse username
    Tweet searchTweetById(int id);
};