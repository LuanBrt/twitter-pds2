#pragma once

#include "controllers/abstractcontroller.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"
#include "models/tweetrepo.hpp"
#include "models/tweet.hpp"
#include "screens/timelinescreen.hpp"
 
#include <vector>

namespace controller {
    class TimelineController: public AbstractController {
    public:
        /// @brief Construtor da classe, que recebe o usuário a qual a timeline pertence
        /// @param u O usuario
        TimelineController(model::User u);


        /// @brief Obtem os tweets do repositorio, e envia para a view exibir
        void getTweets();
        /// @brief Busca tweets no repositorio
        void searchTweets();
        /// @brief Busca usuarios no repositorio
        void searchUsers();


        /// @brief Metodo virtual dos controllers
        /// @return O proximo controller
        AbstractController *render() override;

    private:
        enum ValidOptions {
            EXIT,
            USERCONFIG,
            SEEUSER,
            SEARCHTWEET,
            OPENTREND,
            OPENTWEET,
            SENDTWEET,
            SEARCHUSER,
        };
        std::map<int, std::string> _options;

        model::User _user;
        screen::TimelineScreen _view;
        repo::TweetRepo _tweetRepo;
        repo::UserRepo _userRepo;

    };
}