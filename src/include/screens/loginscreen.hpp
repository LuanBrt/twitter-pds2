#pragma once

#include "screens/abstractscreen.hpp"

#include <vector>
#include <string>
#include "models/user.hpp"

namespace screen {
    class LoginScreen : public AbstractScreen {
        public:
            /// @brief Construtor padrao
            LoginScreen();

            /// @brief  Imprime na tela mensagem de sucesso de login
            /// @param authenticatedUser usúario autenticado
            void successfulLogin(model::User authenticatedUser);

            /// @brief  Imprime na tela mensagem de sucesso de registro
            /// @param registerUser  usúario registrado
            void sucessfulRegister(model::User registerUser);
    };
}
