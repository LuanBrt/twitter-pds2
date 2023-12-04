#include "screens/tweetscreen.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/comment.hpp"
#include "models/commentrepo.hpp"

#include <iostream>

namespace screen {
    TweetScreen::TweetScreen() {
        _title = "Opções:";
    }

    void TweetScreen::renderTweet(model::Tweet tweet) {
        repo::CommentRepo _commentRepo;
        repo::TweetRepo _tweetRepo;

        model::Tweet tr = _tweetRepo.searchTweetById(tweet.id());

        std::cout << "AUTOR: " << tr.author().username() << std::endl;
        std::cout << "CONTEÚDO: \n" << "    - " << tr.description() << std::endl;
        std::cout << "LIKES: " << tr.likes() <<
            "   HORÁRIO: " << tr.timestamp() << std::endl;

        std::vector<model::Comment> commentVector = _commentRepo.getCommentsByTweetId(tweet.id());
        if (commentVector.size() > 0) {
            std::cout << "COMENTÁRIOS: " << std::endl;
        }
        for (model::Comment comment : commentVector) {
            std::cout << "  Autor do Comentário: " << comment.author().username() << std::endl;
            std::cout << "      Descrição do Comentário: \n" << "           - " <<comment.description() << std::endl;
        }
    }
}