#include "controllers/timelinecontroller.hpp"

#include <iostream>
#include <map>
#include <string>

#include "models/tweet.hpp"

TimelineController::TimelineController(User u) : _user(u) {
    _options[ValidOptions::EXIT] = "Sair";
    _options[ValidOptions::USERCONFIG] = "Configurar usuário";
    _options[ValidOptions::SEEUSER] = "Ver perfil de usuário";
    _options[ValidOptions::SEARCHTWEET] = "Buscar Tweet";
    _options[ValidOptions::OPENTREND] = "Abrir trending topics";
    _options[ValidOptions::OPENTWEET] = "Abrir tweet";
    _options[ValidOptions::SENDTWEET] = "Tweetar";
    _options[ValidOptions::SEARCHUSER] = "Buscar Usuário";
}

// A SEGUINTE FUNÇÃO RENDERIZA AS OPÇÕES DA TIMELINE E IMPLEMENTA CADA UMA
// DELAS:
AbstractController *TimelineController::render() {
    getTweets();
    _view.renderSeparator();
    int option = _view.renderMenu(_options);
    switch (option) {
        // Sair:
        case EXIT:
            break;
        // Buscar Usuário:
        case SEARCHUSER:
            searchUsers();
            return new TimelineController(_user);
        case SEARCHTWEET:
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

void TimelineController::searchUsers() {
    std::map<std::string, std::string> keyword;

    keyword = _view.renderForm({"Usuário"});

    std::vector<User> users = _userRepo.searchUser(keyword["Usuário"]);
    _view.flushConsole();
    _view.renderSeparator();
    _view.renderMessage("Usuários Encontrados:");
    _view.renderMessage("");
    for (auto user : users) {
        _view.renderMessage(user.nickname());
    }
    _view.renderSeparator();
    _view.renderMessage("timeline");
}
