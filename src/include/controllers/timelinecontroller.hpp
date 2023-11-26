#pragma once

#include "controllers/abstractcontroller.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"
#include "models/tweetrepo.hpp"
#include "models/tweet.hpp"
#include "screens/timelinescreen.hpp"

#include <vector>

class TimelineController: public AbstractController {
public:
    /// @brief Construtor da classe, que recebe o usuário a qual a timeline pertence
    /// @param u O usuario
    TimelineController(User u);


    /// @brief Obtem os tweets do repositorio, e envia para a view exibir
    void getTweets();


    /// @brief Metodo virtual dos controllers
    /// @return O proximo controller
    AbstractController *render() override;
private:
    enum ValidOptions {
        USERCONFIG,
        SEEUSER,
        BUSCATWEET,
        OPENTREND,
        OPENTWEET,
        SENDTWEET 
    };
    std::map<int, std::string> _options;

    User _user;
    TimelineScreen _view;
    TweetRepo _tweetRepo;
    UserRepo _userRepo;

};