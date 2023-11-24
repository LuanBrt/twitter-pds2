#include "controllers/tweetcontroller.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"
#include "models/comment.hpp"
#include "models/commentrepo.hpp"
#include "models/likerepo.hpp"


#include <iostream>
#include <map>


TweetController::TweetController() {
    UserRepo _userRepo;
    User ur = _userRepo.searchUserById(1);

    TweetRepo _tweetRepo;
    Tweet tr = _tweetRepo.searchTweetById(1);

    LikeRepo _likeRepo;
    int likeExistis = _likeRepo.searchLikeByUserId(ur.id(), tr.id());
    
    _options[ValidOptions::EXIT] = "Voltar Para Timeline";
    _options[ValidOptions::LIKE] = (likeExistis) ? "Remover like" : "Curtir Tweet";
    _options[ValidOptions::RETWEET] = "Retweetar Tweet";
    _options[ValidOptions::COMMENT] = "Comentar Tweet";
}

AbstractController *TweetController::render() {

    UserRepo _userRepo;
    User ur = _userRepo.searchUserById(1);

    TweetRepo _tweetRepo;

    Tweet tr = _tweetRepo.searchTweetById(1);

    CommentRepo _commentRepo;

    LikeRepo _likeRepo;


    _tweetScreen.renderTweet(tr);

    int selected = _tweetScreen.renderMenu(_options);
    switch (selected) {
        
        // Sair
        case ValidOptions::EXIT: {
            exit(0);
            break;
        }

        case ValidOptions::LIKE: {
            if (_likeRepo.searchLikeByUserId(ur.id(), tr.id())) {
                _likeRepo.deleteLike(ur.id(), tr.id());
                _tweetRepo.dislikeTweet(tr.id());
                std::cout << "Você removeu a curtida desse tweet!" << std::endl;
            } else {
                _likeRepo.addLike(ur.id(), tr.id());
                _tweetRepo.likeTweet(tr.id());
                std::cout << "Você curtiu o tweet!" << std::endl;
            }
            return new TweetController();
        }

        // Obter credenciais de login
        case ValidOptions::COMMENT: {
            std::map<std::string, std::string> response = _tweetScreen.renderForm({"Comentário"});
            std::string description = response["Comentário"];
            Comment comment(ur.id(), tr.id(), description);
            _commentRepo.addComment(comment);
            return new TweetController();
        }

    }
    return nullptr;
}