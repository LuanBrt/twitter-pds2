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

namespace controller {
    //Constructor
    //Descrição: Inicializa um controlador de tweets, configurando opções com base no estado atual do tweet, como curtidas existentes.
    TweetController::TweetController() {
        repo::UserRepo _userRepo;
        model::User ur = _userRepo.searchUserById(1);

        repo::TweetRepo _tweetRepo;
        model::Tweet tr = _tweetRepo.searchTweetById(1);

        repo::LikeRepo _likeRepo;
        int likeExistis = _likeRepo.searchLikeByUserId(ur.id(), tr.id());
        
        _options[ValidOptions::EXIT] = "Voltar Para Timeline";
        _options[ValidOptions::LIKE] = (likeExistis) ? "Remover like" : "Curtir Tweet";
        _options[ValidOptions::RETWEET] = "Retweetar Tweet";
        _options[ValidOptions::COMMENT] = "Comentar Tweet";
    }

    //Render
    //Controla a interface de usuário relacionada a um tweet específico, permitindo a interação do usuário, como curtir, retweetar e comentar.
    //AbstractController*: Retorna um ponteiro para um novo controlador, representando a próxima tela a ser exibida após as interações do usuário.
    AbstractController *TweetController::render() {

        repo::UserRepo _userRepo;
        model::User ur = _userRepo.searchUserById(1);

        repo::TweetRepo _tweetRepo;

        model::Tweet tr = _tweetRepo.searchTweetById(1);

        repo::CommentRepo _commentRepo;

        repo::LikeRepo _likeRepo;


        _tweetScreen.renderTweet(tr);

        int selected = _tweetScreen.renderMenu(_options);
        switch (selected) {
            
            // Sair
            case ValidOptions::EXIT: {
                exit(0);
                break;
            }
            // Curtir e remover curtida do tweet
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
                model::Comment comment(ur.id(), tr.id(), description);
                _commentRepo.addComment(comment);
                return new TweetController();
            }

        }
        return nullptr;
    }
}