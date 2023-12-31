#pragma once

#include "controllers/abstractcontroller.hpp"
#include "controllers/userprofilecontroller.hpp"
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


        /// @brief Metodo virtual dos controllers
        /// @return O proximo controller
        AbstractController *render() override;


        /// @brief Obtem os tweets do repositorio, e envia para a view exibir
        void getTweets();
        /// @brief Obtem um usuário e entra no profile dele
        void seeUser();
        /// @brief Busca tweets no repositorio
        void searchTweets();
        /// @brief Busca usuarios no repositorio
        void searchUsers();

        /// @brief Função que publica um tweet
        void sendTweet();


    private:
        enum ValidOptions {
            EXIT,
            SEEUSER,
            SEARCHTWEET,
            SENDTWEET,
            SEARCHUSER,
        };
        std::map<int, std::string> _options;

        model::User _user;
        screen::TimelineScreen _timelineScreen;
        repo::TweetRepo _tweetRepo;
        repo::UserRepo _userRepo;

    };
}
