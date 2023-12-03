#pragma once

#include "screens/abstractscreen.hpp"
#include "models/tweet.hpp"

#include <vector>
#include <string>

class TweetScreen : public AbstractScreen {
    public:
        /// @brief O construtor inicializa a tela de tweet com o título padrão "Opções".
        TweetScreen();

        /// @brief Renderiza as informações detalhadas de um tweet, incluindo autor, conteúdo, número de curtidas, horário de postagem e comentários associados.
        /// @param tweet O tweet a ser renderizado.
        void renderTweet(Tweet tweet);
};