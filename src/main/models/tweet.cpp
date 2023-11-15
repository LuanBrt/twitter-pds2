#include "models/tweet.hpp"
#include "models/comment.hpp"

Tweet::Tweet(int id, const std::string author, const std::string description, const std::string timestamp, int likes)
    : _id(id), _author(author), _description(description), _timestamp(timestamp), _likes(likes) {}


int Tweet::getId() const{
  return _id;
}

std::string Tweet::getAuthor() {
    return _author;
}

std::string Tweet::getDescription() {
    return _description;
}

std::string Tweet::getTimestamp() {
    return _timestamp;
}

int Tweet::getLikes() {
    return _likes;
}

const std::vector<Comment> Tweet::getComments() {
    return _comments;
}

void Tweet::addComment(const std::string commentDescription, const std::string commentAuthor) {
    Comment* newComment = new Comment(commentDescription, commentAuthor, Tweet::getId());
    _comments.push_back(*newComment);
}

Tweet Tweet::getTweetById(int id, const std::vector<Tweet> tweets) {
    for (const auto tweet : tweets) {
        if (tweet.getId() == id) {
            return tweet;
        }
    }

    // Se não encontrar, retorna um tweet "vazio" (os atributos não são garantidos)
    return Tweet(-1, "", "", "", 0);
}