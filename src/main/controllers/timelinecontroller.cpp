#include "controllers/timelinecontroller.hpp"
#include "models/tweet.hpp"

#include <map>
#include <iostream>
#include <string>

TimelineController::TimelineController(User u): _user(u) {
    _options[ValidOptions::USERCONFIG] = "Configurar usuário";
    _options[ValidOptions::SEEUSER] = "Ver perfil de usuário";
    _options[ValidOptions::BUSCATWEET] = "Buscar Tweet";
    _options[ValidOptions::OPENTREND] = "Abrir trending topics";
    _options[ValidOptions::OPENTWEET] = "Abrir tweet";
    _options[ValidOptions::SENDTWEET] = "Tweetar";
}

AbstractController *TimelineController::render() {
    getTweets();
    int option = _view.renderMenu(_options);
    switch (option) {
        case 0:
            break;
        case 2:
            searchTweets();
            return new TimelineController(_user);
        default:
            return new TimelineController(_user);

    }
    return nullptr;
}

void TimelineController::getTweets() {
    std::vector<Tweet> response = _tweetRepo.getUserTimeline(_user);
    _view.renderTweetList(response);
    
}

void TimelineController::searchTweets() {
    std::string searchString;
    std::cout << "Digite a palavra-chave para busca: ";
    std::getline(std::cin >> std::ws, searchString);


    std::vector<Tweet> matchingTweets = _tweetRepo.searchTweets(searchString);

    // exibindo os tweets encontrados
    _view.renderTweetList(matchingTweets);
}
