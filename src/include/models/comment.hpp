#pragma once

#include "models/user.hpp"
#include "models/tweet.hpp" 

#include <string>


class Comment {
public:
    Comment(int authorId, int tweetId, std::string description)
    : _authorId(authorId), _tweetId(tweetId), _description(description) {}
    Comment(int id, int authorId, int tweetId, std::string description)
    : _id(id), _authorId(authorId), _tweetId(tweetId), _description(description)  {}

    int id();
    std::string description();
    User author();
    Tweet tweet();

private:
    int _id;
    int _authorId;
    int _tweetId;
    std::string _description;
};
