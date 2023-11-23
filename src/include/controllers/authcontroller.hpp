#pragma once

#include "controllers/abstractcontroller.hpp"
#include "screens/loginscreen.hpp"
#include "models/userrepo.hpp"

#include <map>

class AuthController: public AbstractController {
    public:
        /// @brief Construtor padrao
        AuthController();

        /// @brief Renderiza uma tela para o usuario e obtem inputs do mesmo
        /// @return Novo controlador de uma nova tela
        AbstractController *render() override;
    private:
        enum ValidOptions {
            EXIT,
            LOGIN,
            REGISTER, 
        };
        std::map<int, std::string> _options;

        LoginScreen _loginScreen;
        UserRepo _repo;
};