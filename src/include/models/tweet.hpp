#pragma once
#include <string>
#include <vector>
#include "models/comment.hpp"

class Tweet {
public:
    Tweet(int id, std::string author, std::string description, std::string timestamp, int likes);

    int getId() const;
    std::string getAuthor();
    std::string getDescription();
    std::string getTimestamp();
    int getLikes();
    std::vector<Comment> getComments();

    void addComment(std::string commentDescription, std::string commentAuthor);
    static Tweet getTweetById(int id, std::vector<Tweet> tweets);

private:
    int _id;
    std::string _author;
    std::string _description;
    std::string _timestamp;
    int _likes;
    std::vector<Comment> _comments;
};
