#pragma once

#include "models/user.hpp"
#include "models/tweet.hpp" 

#include <string>


class Comment {
public:
    /// @brief construtor usado para criar um novo comentário
    /// @param authorId Identificador único do autor do comentário
    /// @param tweetId Identificador único do tweet ao qual o comentário está vinculado
    /// @param description Descrição do comentário
    Comment(int authorId, int tweetId, std::string description)
    : _authorId(authorId), _tweetId(tweetId), _description(description) {}

    /// @brief construtor utilizado quando á se possui um identificador único associado ao comentário
    /// @param id Identificador único do comentário
    /// @param authorId Identificador único do autor do comentário
    /// @param tweetId Identificador único do tweet ao qual o comentário está vinculado
    /// @param description Descrição do comentário
    Comment(int id, int authorId, int tweetId, std::string description)
    : _id(id), _authorId(authorId), _tweetId(tweetId), _description(description)  {}

    /// @brief Retorna o identificador único associado ao comentário
    /// @return Retorna o identificador único associado ao comentário
    int id();

    /// @brief Retorna a descrição do comentário
    /// @return Retorna a descrição do comentário
    std::string description();

    /// @brief Retorna o autor do comentário. Cria uma instância de User consultando o repositório de usuários com base no identificador do autor (_authorId)
    /// @return Retorna o autor do comentário
    User author();

    /// @brief Retorna o tweet ao qual o comentário está vinculado. Cria uma instância de Tweet consultando o repositório de tweets com base no identificador do tweet (_tweetId).
    /// @return Retorna o tweet ao qual o comentário está vinculado.
    Tweet tweet();

private:
    int _id;
    int _authorId;
    int _tweetId;
    std::string _description;
};
