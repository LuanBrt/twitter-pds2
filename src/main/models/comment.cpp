#include "models/comment.hpp"

std::string Comment::getDescription() {
    return _description;
}

std::string Comment::getAuthor() {
    return _author;
}

int Comment::getTweetReference() {
    return _tweetReference;
}
