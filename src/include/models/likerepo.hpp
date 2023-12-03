#pragma once

#include "models/abstractrepo.hpp"

#include <string>
#include <vector>

class LikeRepo : public AbstractRepo {
public:
    /// @brief Adiciona uma nova entrada de "curtida" ao banco de dados, associando um usuário a um tweet.
    /// @param userId Identificador único do usuário que está curtindo.
    /// @param tweetId Identificador único do tweet que está sendo curtido.
    void addLike(int userId, int tweetId);
    
    /// @brief Verifica se um usuário já curtiu um tweet específico no banco de dados.
    /// @param userId Identificador único do usuário.
    /// @param tweetId Identificador único do tweet.
    /// @return Retorna o número de curtidas encontradas.
    int searchLikeByUserId(int userId, int tweetId);

    /// @brief Exclui uma "curtida" associada a um usuário e a um tweet específicos no banco de dados.
    /// @param userId Identificador único do usuário.
    /// @param tweetId Identificador único do tweet.
    void deleteLike(int userId, int tweetId);
};