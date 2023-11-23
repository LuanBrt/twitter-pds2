#pragma once

#include "models/abstractrepo.hpp"
#include "models/tweet.hpp"

#include <string>
#include <vector>

class TweetRepo : public AbstractRepo {
public:

    /// @brief Adiciona um tweet ao banco de dados
    /// @param tweet 
    /// @return Retorna o próprio tweet criado caso sucesso e um throw de erro caso dê errado
    Tweet addTweet(Tweet tweet);

    /// @brief Pega todos os tweets do banco de dados
    /// @return Retorna uma lista de todos os tweets do banco de dados
    std::vector<Tweet> getTweets();


    /// @brief Busca um tweet específico com esse id
    /// @param id
    /// @return Retorna o tweet que contém o id especificado
    Tweet searchTweetById(int id);
};