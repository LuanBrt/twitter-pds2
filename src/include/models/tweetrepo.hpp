#pragma once

#include "models/abstractrepo.hpp"
#include "models/tweet.hpp"

#include <string>
#include <vector>

namespace repo {
    class TweetRepo : public AbstractRepo {
    public:
        /// @brief Adiciona um tweet ao banco de dados
        /// @param tweet 
        /// @return Retorna o próprio tweet criado caso sucesso e um throw de erro caso dê errado
        model::Tweet addTweet(model::Tweet tweet);

        /// @brief Pega todos os tweets do banco de dados
        /// @return Retorna uma lista de todos os tweets do banco de dados
        std::vector<model::Tweet> getTweets();


        /// @brief Busca um tweet específico com esse id
        /// @param id
        /// @return Retorna o tweet que contém o id especificado
        model::Tweet searchTweetById(int id);

        void likeTweet(int id);

        void dislikeTweet(int id);
        
        std::vector<model::Tweet> searchTweets(std::string searchString);

        /// @brief Obtem os tweets para a timeline de determinado user
        /// @param u O usuario
        /// @return Um vetor com os tweets
        std::vector<model::Tweet> getUserTimeline(model::User u);
    };
}