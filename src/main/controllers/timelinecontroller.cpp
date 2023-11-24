#include "controllers/timelinecontroller.hpp"
#include "models/tweet.hpp"

#include <vector>

TimelineController::TimelineController(User u): _user(u) {
    _options[ValidOptions::USERCONFIG] = "Configurar usuário";
    _options[ValidOptions::SEEUSER] = "Ver perfil de usuário";
    _options[ValidOptions::BUSCATWEET] = "Buscar Tweet";
    _options[ValidOptions::OPENTREND] = "Abrir trending topics";
    _options[ValidOptions::OPENTWEET] = "Abrir tweet";
    _options[ValidOptions::SENDTWEET] = "Tweetar";
}

AbstractController *TimelineController::render() {
    // obtendo os tweets de pessoas que o usuario segue
    std::vector<Tweet> tweets = _repo.get
}

std::vector<Tweet> TimelineController::getTweets() {
    std::vector<User> following = repo.getFollowing(_user);
}
