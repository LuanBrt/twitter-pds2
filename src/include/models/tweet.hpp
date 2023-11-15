#pragma once
#include <string>
#include <vector>
#include "models/comment.hpp"

class Tweet {
public:
    Tweet(int id, const std::string author, const std::string description, const std::string timestamp, int likes);

    int getId() const;
    std::string getAuthor();
    std::string getDescription();
    std::string getTimestamp();
    int getLikes();
    const std::vector<Comment> getComments();

    void addComment(const std::string commentDescription, const std::string commentAuthor);
    static Tweet getTweetById(int id, const std::vector<Tweet> tweets);

private:
    int _id;
    std::string _author;
    std::string _description;
    std::string _timestamp;
    int _likes;
    std::vector<Comment> _comments;
};
