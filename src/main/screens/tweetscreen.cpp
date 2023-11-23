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
    std::cout << RED << "Autor: " << RESET << tweet.author().username() << std::endl;
    std::cout << RED << "Conteúdo: \n" << RESET << tweet.description() << std::endl;
    std::cout << BLUE << "Likes: " << RESET << tweet.likes() << BLUE <<
        "   Horário: " << RESET << tweet.timestamp() << std::endl;
}