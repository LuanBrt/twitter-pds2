#pragma once

#include <string>

namespace model {
    class User {
    public:
        /// @brief construtor padrão do usuário
        /// @param username Nome de usuário
        /// @param password Senha
        /// @param nickname Apelido
        User(std::string username, std::string password, std::string nickname): _username(username), _password(password), _nickname(nickname) {}

        /// @brief construtor padrão do usuário
        /// @param id Identificador único do usuário
        /// @param username Nome de usuário
        /// @param password Senha
        /// @param nickname Apelido
        User(int id, std::string username, std::string password, std::string nickname): _id(id), _username(username), _password(password), _nickname(nickname) {}
        int id();

        /// @brief função que retorna o nome de usuário
        std::string username();

        /// @brief função que retorna a senha do usuário
        std::string password();

        /// @brief função que retorna o apelido do usuário
        std::string nickname();
        
    private:
        int _id;
        std::string _username;
        std::string _password;
        std::string _nickname;
    };
}