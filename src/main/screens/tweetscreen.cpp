#include "screens/tweetscreen.hpp"
#include "models/tweet.hpp"
#include "models/comment.hpp"

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

TweetScreen::TweetScreen() {
    _title = "Opções:";
}

void TweetScreen::renderTweet(Tweet tweet) {
    std::cout << RED << "Autor: " << RESET << tweet.getAuthor() << std::endl;
    std::cout << RED << "Conteúdo: \n" << RESET << tweet.getDescription() << std::endl;
    std::cout << BLUE << "Likes: " << RESET << tweet.getLikes() << BLUE <<
        "   Horário: " << RESET << tweet.getTimestamp() << std::endl;
    
    std::vector<Comment> comments = tweet.getComments();

    std::cout << RED << "Comentários: \n" << RESET;
    for (Comment comment : comments) {
        std::cout << "Autor do Comentário: " << comment.getAuthor() << std::endl;
        std::cout << "Descrição do Comentário: " << comment.getDescription() << std::endl;
        std::cout << std::endl;
    }
}