#include "controllers/timelinecontroller.hpp"

#include <iostream>
#include <map>
#include <string>
#include <ctime>

#include "models/tweet.hpp"

namespace controller {
    TimelineController::TimelineController(model::User u) : _user(u) {
        _options[ValidOptions::EXIT] = "Sair";
        _options[ValidOptions::SEEUSER] = "Ver perfil de usuário";
        _options[ValidOptions::SEARCHTWEET] = "Buscar Tweet";
        _options[ValidOptions::SENDTWEET] = "Tweetar";
        _options[ValidOptions::SEARCHUSER] = "Buscar Usuário";
    }

    // A SEGUINTE FUNÇÃO RENDERIZA AS OPÇÕES DA TIMELINE E IMPLEMENTA CADA UMA
    // DELAS:
    AbstractController *TimelineController::render() {
        getTweets();
        _timelineScreen.renderSeparator();
        int option = _timelineScreen.renderMenu(_options);
        switch (option) {
            // Sair:
            case EXIT: {
                break;
            };

            case SEEUSER: {
                seeUser();
                return new TimelineController(_user);
            };

            case SENDTWEET: {
                sendTweet();
                return new TimelineController(_user);
            };

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

    void TimelineController::seeUser() {
        _timelineScreen.flushConsole();
        std::map<std::string,std::string> response = _timelineScreen.renderForm({"Digite o nome do usuário que deseja ver"});
        model::User* resultUser = _userRepo.searchUserByUsername(response["Digite o nome do usuário que deseja ver"]);
        if (resultUser == nullptr) {
            _timelineScreen.renderMessage("Não existe usuário com esse nome!");
        } else {
            UserProfileController userProfileControler = UserProfileController(*resultUser, _user);
            userProfileControler.render();
            _timelineScreen.flushConsole();
        }
    }


    void TimelineController::sendTweet() {
            _timelineScreen.flushConsole();
            std::map<std::string,std::string> response = _timelineScreen.renderForm({"O que você deseja tweetar?"});
            time_t now = time(0);
                model::Tweet InputTweet(_user.id(),response["O que você deseja tweetar?"],asctime(localtime(&now)),0);
                _tweetRepo.addTweet(InputTweet);
                _timelineScreen.flushConsole();
                _timelineScreen.renderSeparator();
                _timelineScreen.renderMessage("Tweet realizado com sucesso!");
                _timelineScreen.renderSeparator();
    }

    void TimelineController::getTweets() {  
        std::vector<model::Tweet> response = _tweetRepo.getUserTimeline(_user);
        _timelineScreen.renderTweetList(response);
    }

    void TimelineController::searchTweets() {
        std::string searchString;
        _timelineScreen.renderMessage("Digite a palavra-chave para busca:");
        std::getline(std::cin >> std::ws, searchString);

        std::vector<model::Tweet> matchingTweets = _tweetRepo.searchTweets(searchString);

        // exibindo os tweets encontrados
        _timelineScreen.renderTweetList(matchingTweets);
    }

    void TimelineController::searchUsers() {
        std::map<std::string, std::string> keyword;
        keyword = _timelineScreen.renderForm({"Usuário"});

        std::vector<model::User> users = _userRepo.searchUser(keyword["Usuário"]);
        _timelineScreen.renderSearchUserResult(users);
    }
}