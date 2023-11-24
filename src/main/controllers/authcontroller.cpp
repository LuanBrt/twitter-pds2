#include "controllers/authcontroller.hpp"
#include "controllers/tweetcontroller.hpp"

#include <iostream>

AuthController::AuthController() {
    _options[ValidOptions::EXIT] = "Sair";
    _options[ValidOptions::LOGIN] = "Entrar";
}

AbstractController *AuthController::render() {
    int selected = _loginScreen.renderMenu(_options);
    switch (selected) {
        
        // Sair
        case ValidOptions::EXIT: {
            exit(0);
            break;
        }
        
        // Obter credenciais de login
        case ValidOptions::LOGIN: {
            std::map<std::string, std::string> response = _loginScreen.renderForm({"Usuario", "Senha"});
            std::cout << response["Usuario"];
            return new TweetController();
        }
    }
    return nullptr;
}