#include "controllers/timelinecontroller.hpp"
#include "models/tweet.hpp"

#include <map>

TimelineController::TimelineController(User u): _user(u) {
    _options[ValidOptions::USERCONFIG] = "Configurar usuário";
    _options[ValidOptions::SEEUSER] = "Ver perfil de usuário";
    _options[ValidOptions::BUSCATWEET] = "Buscar Tweet";
    _options[ValidOptions::OPENTREND] = "Abrir trending topics";
    _options[ValidOptions::OPENTWEET] = "Abrir tweet";
    _options[ValidOptions::SENDTWEET] = "Tweetar";
    _options[ValidOptions::SEARCHUSER] = "Buscar Usuário";
}

AbstractController *TimelineController::render() {
    getTweets();
    int option = _view.renderMenu(_options);
    switch (option) {
        case 0:
            break;
        case 6:
            std::map<std::string,std::string> keyword;

            keyword = _searchController.renderForm({"Usuário"});

            std::vector<User> users = _userRepo.searchUser(keyword["Usuário"]);

            _view.renderTextSearchUser(users);

            return new TimelineController(_user);

    }
    return nullptr;
}

void TimelineController::getTweets() {
    std::vector<Tweet> response = _tweetRepo.getUserTimeline(_user);
    _view.renderTweetList(response);
    
}
