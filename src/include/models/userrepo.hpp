#pragma once

#include "models/abstractrepo.hpp"
#include "models/user.hpp"

#include <string>
#include <vector>

class UserRepo : public AbstractRepo {
public:

    /// @brief Adiciona um usuario ao banco de dados
    /// @param user 
    /// @return Retorna o próprio usuário criado caso sucesso e um throw de erro caso dê errado
    User addUser(User user);


    /// @brief Busca usuário baseado em uma keyword
    /// @param keyword
    /// @return Retorna uma lista de usuarios que contenham a chave especificada no userame
    std::vector<User> searchUser(std::string keyword);

    /// @brief Busca usúario baseado em um id
    /// @param id
    /// @return Retorna o usuário específico com esse id
    User searchUserById(int id);

    std::vector<User> getFollowing(User u);

    User followUser(User follower, User following);
};