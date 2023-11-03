#pragma once

#include "controllers/abstractcontroller.hpp"
#include "screens/loginscreen.hpp"


#include <map>

class AuthController: public AbstractController {
    public:
        AuthController();
        AbstractController *render() override;
    private:
        enum ValidOptions {
            EXIT,
            LOGIN,
            REGISTER, 
        };
        std::map<int, std::string> _options;
        LoginScreen _loginScreen;

};