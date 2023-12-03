#pragma once

#include "controllers/abstractcontroller.hpp"
#include "screens/tweetscreen.hpp"


#include <map>

class TweetController: public AbstractController {
public:
    /// @brief Inicializa um controlador de tweets, configurando opções com base no estado atual do tweet, como curtidas existentes.
    TweetController();
    /// @brief Controla a interface de usuário relacionada a um tweet específico, permitindo a interação do usuário, como curtir, retweetar e comentar.
    /// @return Retorna um ponteiro para um novo controlador, representando a próxima tela a ser exibida após as interações do usuário.
    AbstractController *render() override;
private:
    //enum com as opções de interação do usuário com o tweet
    enum ValidOptions {
        EXIT,
        LIKE,
        RETWEET,
        COMMENT, 
    };
    std::map<int, std::string> _options;
    TweetScreen _tweetScreen;

};
