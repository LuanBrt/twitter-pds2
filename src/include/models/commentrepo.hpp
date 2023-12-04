#pragma once

#include "models/abstractrepo.hpp"
#include "models/comment.hpp"

#include <string>
#include <vector>

namespace repo {
class CommentRepo : public AbstractRepo {
public:
    /// @brief Adiciona um comentário ao banco de dados
    /// @param comment
    /// @return Retorna o próprio comentário criado caso sucesso e um throw de erro caso dê errado
    model::Comment addComment(model::Comment comment);

    /// @brief Pega todos os tweets do banco de dados
    /// @param tweetId   
    /// @return Retorna uma lista de todos os tweets do banco de dados
    std::vector<model::Comment> getCommentsByTweetId(int tweetId);


    /// @brief Busca tweets que foram enviados por um usuario com esse username
    /// @param id
    /// @return Retorna uma lista de tweets que contenham o author como esse username
    model::Comment searchCommentById(int id);
};
}