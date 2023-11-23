#pragma once
#include <string>
#include <vector>
#include "models/user.hpp"

class Tweet {
public:
    Tweet(int authorId, std::string description, std::string timestamp, int likes): 
        _authorId(authorId), _description(description), _timestamp(timestamp), _likes(likes) {};
    Tweet(int id, int authorId, std::string description, std::string timestamp, int likes):
        _id(id), _authorId(authorId), _description(description), _timestamp(timestamp), _likes(likes) {};

    int id();
    User author();
    std::string description();
    std::string timestamp();
    int likes();

    Tweet getTweetById(int id, std::vector<Tweet> tweets);

private:
    int _id;
    int _authorId;
    std::string _description;
    std::string _timestamp;
    int _likes;
};