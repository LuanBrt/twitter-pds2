#include "screens/tweetscreen.hpp"
#include "models/tweet.hpp"
#include "models/tweetrepo.hpp"
#include "models/comment.hpp"
#include "models/commentrepo.hpp"

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

TweetScreen::TweetScreen() {
    _title = "Opções:";
}

void TweetScreen::renderTweet(Tweet tweet) {
    CommentRepo _commentRepo;
    TweetRepo _tweetRepo;

    Tweet tr = _tweetRepo.searchTweetById(tweet.id());

    std::cout << RED << "AUTOR: " << RESET << tr.author().username() << std::endl;
    std::cout << RED << "CONTEÚDO: \n" << RESET << "    - " << tr.description() << std::endl;
    std::cout << BLUE << "LIKES: " << RESET << tr.likes() << BLUE <<
        "   HORÁRIO: " << RESET << tr.timestamp() << std::endl;

    std::vector<Comment> commentVector = _commentRepo.getCommentsByTweetId(tweet.id());
    if (commentVector.size() > 0) {
        std::cout << RED << "COMENTÁRIOS: " << RESET << std::endl;
    }
    for (Comment comment : commentVector) {
        std::cout << "  Autor do Comentário: " << comment.author().username() << std::endl;
        std::cout << "      Descrição do Comentário: \n" << "           - " <<comment.description() << std::endl;
    }
}