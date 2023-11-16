#pragma once

#include "models/abstractrepo.hpp"
#include "models/user.hpp"

#include <string>
#include <vector>

class UserRepo : public AbstractRepo {
public:

    /// @brief Adiciona um usuario ao banco de dados
    /// @param user 
    /// @return Retorna 1 caso sucesso e 0 caso erro
    int addUser(User user);


    /// @brief Busca usuário baseado em uma keyword
    /// @param keyword
    /// @return Retorna uma lista de usuarios que contenham a chave especificada no userame
    std::vector<User> searchUser(std::string keyword);
};