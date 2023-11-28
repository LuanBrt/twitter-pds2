#include "controllers/authcontroller.hpp"
#include "controllers/timelinecontroller.hpp"

// temp
#include "models/userrepo.hpp"
#include "models/user.hpp"
#include "models/tweetrepo.hpp"
#include "models/tweet.hpp"


#include <iostream>

AuthController::AuthController() {
    _options[ValidOptions::EXIT] = "Sair";
    _options[ValidOptions::LOGIN] = "Entrar";
}

AbstractController *AuthController::render() {
    int selected = _loginScreen.renderMenu(_options);
    switch (selected) {
        
        // Sair
        case ValidOptions::EXIT: {
            exit(0);
            break;
        }
        
        // Obter credenciais de login
        case ValidOptions::LOGIN: {
            std::map<std::string, std::string> response = _loginScreen.renderForm({"Usuario", "Senha"});
            UserRepo userRepo;
            TweetRepo tweetRepo;
            User r1 = userRepo.addUser(User("luan", "123456", "Luan Borges"));
            User r2 = userRepo.addUser(User("marquezintop", "123456", "Marquez"));
            userRepo.followUser(r1, r2);
            Tweet tweet1(r2.id(), "meu tweet de teste", "2023", 0);
            Tweet tweet2(r1.id(), "tweet de teste", "2023", 0);

            tweetRepo.addTweet(tweet1);
            tweetRepo.addTweet(tweet2);


            return new TimelineController(r1);
        }
    }
    return nullptr;
}