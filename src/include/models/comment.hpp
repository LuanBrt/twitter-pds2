#pragma once
#include <string>

class Tweet;

class Comment {
public:
    Comment(const std::string& description, const std::string& author, Tweet* tweetReference);

    std::string getDescription() const;
    std::string getAuthor() const;
    Tweet* getTweetReference() const;

    void addCommentToTweet();

private:
    std::string _description;
    std::string _author;
    Tweet* _tweetReference;
};
