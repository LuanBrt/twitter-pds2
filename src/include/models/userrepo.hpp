#pragma once

#include "models/abstractrepo.hpp"
#include "models/user.hpp"

#include <string>
#include <vector>

namespace repo {
    class UserRepo : public AbstractRepo {
    public:

        /// @brief Adiciona um usuario ao banco de dados
        /// @param user 
        /// @return Retorna o próprio usuário criado caso sucesso e um throw de erro caso dê errado
        model::User addUser(model::User user);


        /// @brief Busca usuário baseado em uma keyword
        /// @param keyword
        /// @return Retorna uma lista de usuarios que contenham a chave especificada no userame
        std::vector<model::User> searchUser(std::string keyword);

        /// @brief Busca usúario baseado em um id
        /// @param id
        /// @return Retorna o usuário específico com esse id
        model::User searchUserById(int id);


        /// @brief Obtem uma lista de todos os seguidos de um usuario
        /// @param u O usuário
        /// @return Um vetor com os seguidos
        std::vector<model::User> getFollowing(model::User u);

        /// @brief Adiciona o following a lista de seguidors do follower
        /// @param follower Usuario que vai seguir
        /// @param followed Usuario seguido
        /// @return O usuario seguido
        model::User followUser(model::User follower, model::User followed);
    };
}