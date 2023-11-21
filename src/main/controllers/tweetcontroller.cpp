#include "controllers/tweetcontroller.hpp"
#include "models/tweet.hpp"

#include <iostream>
#include <map>


TweetController::TweetController() {
    _options[ValidOptions::EXIT] = "Voltar Para Timeline";
    _options[ValidOptions::LIKE] = "Curtir Tweet";
    _options[ValidOptions::RETWEET] = "Retweetar Tweet";
    _options[ValidOptions::COMMENT] = "Comentar Tweet";
}

AbstractController *TweetController::render() {

    std::vector<Tweet> tweetVector;

    tweetVector.push_back(Tweet(1, "AutorTweet", "Conteúdo do Tweet", "2023-01-01 12:00:00", 0));
    tweetVector.push_back(Tweet(2, "AutorTweet2", "Conteúdo do Tweet2", "2023-01-01 12:00:00", 1));

    Tweet tweet = Tweet::getTweetById(2, tweetVector);

    _tweetScreen.renderTweet(tweet);

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
            tweet.addComment(comment, username);
            _tweetScreen.renderTweet(tweet);
        }
    }
    return nullptr;
}