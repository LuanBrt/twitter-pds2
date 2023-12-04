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


    /// @brief Obtem uma lista de todos os seguidos de um usuario
    /// @param u O usuário
    /// @return Um vetor com os seguidos
    std::vector<User> getFollowing(User u);

    /// @brief Checa se o usuário já foi seguido
    /// @param follower Usuario seguidor
    /// @param followed Usuario seguido
    /// @return 1 se o usuário realmente é seguido pelo follower e 0 caso não
    int isUserFollow(User follower, User followed);

    /// @brief Adiciona o following a lista de seguidors do follower
    /// @param follower Usuario que vai seguir
    /// @param followed Usuario seguido
    /// @return O usuario seguido
    User followUser(User follower, User followed);
};