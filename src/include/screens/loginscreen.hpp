#pragma once

#include "screens/abstractscreen.hpp"

#include <vector>
#include <string>
#include "models/user.hpp"

class LoginScreen : public AbstractScreen {
    public:
        /// @brief Construtor padrao
        LoginScreen();

        void successfulLogin(User authenticatedUser);
        void sucessfulRegister(User registerUser);
};