#include "models/tweet.hpp"
#include "models/comment.hpp"

Tweet::Tweet(const std::string& author, const std::string& description, const std::string& timestamp, int likes)
    : _author(author), _description(description), _timestamp(timestamp), _likes(likes) {}

std::string Tweet::getAuthor() const {
    return _author;
}

std::string Tweet::getDescription() const {
    return _description;
}

std::string Tweet::getTimestamp() const {
    return _timestamp;
}

int Tweet::getLikes() const {
    return _likes;
}

const std::vector<Comment> Tweet::getComments() const {
    return _comments;
}

void Tweet::addComment(const std::string& commentDescription, const std::string& commentAuthor) {
    Comment* newComment = new Comment(commentDescription, commentAuthor, this);
    _comments.push_back(*newComment);
}