#include "screens/tweetscreen.hpp"
#include <iostream>
#include "models/tweet.hpp"

TweetScreen::TweetScreen() {
    std::vector<Tweet> tweetVector;

    tweetVector.push_back(Tweet(1, "AutorTweet", "Conteúdo do Tweet", "2023-01-01 12:00:00", 0));
    tweetVector.push_back(Tweet(2, "AutorTweet2", "Conteúdo do Tweet2", "2023-01-01 12:00:00", 1));

    Tweet tweet = Tweet::getTweetById(1, tweetVector);

    _title = "Tweet";
    std::cout << "Autor: " << tweet.getAuthor() << std::endl;
}

