#pragma once
#include <string>
#include <vector>

class Comment;

class Tweet {
public:
    Tweet(const std::string& author, const std::string& description, const std::string& timestamp, int likes);

    std::string getAuthor() const;
    std::string getDescription() const;
    std::string getTimestamp() const;
    int getLikes() const;
    const std::vector<Comment> getComments() const;
    
    void addComment(const std::string& commentDescription, const std::string& commentAuthor);

private:
    std::string _author;
    std::string _description;
    std::string _timestamp;
    int _likes;
    std::vector<Comment> _comments;
};
