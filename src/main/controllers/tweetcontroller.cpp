#include "controllers/tweetcontroller.hpp"

#include <iostream>
#include <map>

TweetController::TweetController() {
    _options[ValidOptions::EXIT] = "Voltar Para Timeline";
    _options[ValidOptions::LIKE] = "Curtir Tweet";
    _options[ValidOptions::RETWEET] = "Retweetar Tweet";
    _options[ValidOptions::COMMENT] = "Comentar Tweet";
}

AbstractController *TweetController::render() {
    int selected = _tweetScreen.renderMenu(_options);
    switch (selected) {
        
        // Sair
        case ValidOptions::EXIT: {
            exit(0);
            break;
        }

        // Obter credenciais de login
        case ValidOptions::COMMENT: {
            std::map<std::string, std::string> response = _tweetScreen.renderForm({"Usuario", "Comentário"});
            return nullptr;
        }
    }
    return nullptr;
}