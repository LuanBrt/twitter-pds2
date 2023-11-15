#pragma once
#include <string>

class Comment {
public:
    Comment(const std::string description, const std::string author, int tweetReference)
    : _description(description), _author(author), _tweetReference(tweetReference) {}

    std::string getDescription();
    std::string getAuthor();
    int getTweetReference();

private:
    std::string _description;
    std::string _author;
    int _tweetReference;
};
