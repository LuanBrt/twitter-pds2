#include "controllers/tweetcontroller.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/userrepo.hpp"
#include "models/user.hpp"

#include <iostream>
#include <map>


TweetController::TweetController() {
    _options[ValidOptions::EXIT] = "Voltar Para Timeline";
    _options[ValidOptions::LIKE] = "Curtir Tweet";
    _options[ValidOptions::RETWEET] = "Retweetar Tweet";
    _options[ValidOptions::COMMENT] = "Comentar Tweet";
}

AbstractController *TweetController::render() {

    UserRepo _userRepo;
    User user("luan", "123", "teste");

    User ur = _userRepo.addUser(user);

    TweetRepo _tweetRepo;
    Tweet tweet(ur.id(), "testee", "21/11/2023", 0);

    Tweet tr = _tweetRepo.addTweet(tweet);

    _tweetScreen.renderTweet(tr);

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
            std::string username = response["Usuario"];
            std::string comment = response["Comentário"];
            _tweetScreen.renderTweet(tweet);
        }
    }
    return nullptr;
}