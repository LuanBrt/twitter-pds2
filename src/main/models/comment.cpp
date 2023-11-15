#include "models/comment.hpp"
#include "models/tweet.hpp"

Comment::Comment(const std::string& description, const std::string& author, Tweet* tweetReference)
    : _description(description), _author(author), _tweetReference(tweetReference) {}

std::string Comment::getDescription() const {
    return _description;
}

std::string Comment::getAuthor() const {
    return _author;
}

Tweet* Comment::getTweetReference() const {
    return _tweetReference;
}
