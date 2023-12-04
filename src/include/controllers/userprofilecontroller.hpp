#pragma once

#include "controllers/abstractcontroller.hpp"
#include "screens/userprofilescreen.hpp"
#include "screens/timelinescreen.hpp"
#include "models/userrepo.hpp"
#include "models/tweetrepo.hpp"

#include <string>
#include <map>

class UserProfileController: public AbstractController {
    public:
        /// @brief Construtor da classe, que recebe o usuário a qual o perfil pertence
        /// @param u O usuario
        UserProfileController(User user, User loggedUser);

        /// @brief Renderiza uma tela para o usuario e obtem inputs do mesmo
        /// @return Novo controlador de uma nova tela
        AbstractController *render() override;

        /// @brief Obtém informações do usuário atual do controller.
        void getUser();

        /// @brief Permite que o usuário atual siga o usuário do controller.
        void followUser();

    private:

        // Enum com as opções do formulário do menu de autenticação:
        enum ValidOptions {
            EXIT,
            FOLLOWUSER,
            OPENTWEET,
        };
        std::map<int, std::string> _options;
        UserProfileScreen _userProfileScreen;
        TimelineScreen _timelineScreen;
        User _user; 
        User _loggedUser;
        UserRepo _userRepo;
        TweetRepo _tweetRepo;
        bool _isFollowed;
};