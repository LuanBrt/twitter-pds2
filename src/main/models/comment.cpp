#include "models/comment.hpp"
#include "models/tweet.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"
#include "models/tweetrepo.hpp"

int Comment::id() {
    return _id;
}

std::string Comment::description() {
    return _description;
}

User Comment::author() {
    UserRepo _repo;
    return _repo.searchUserById(_authorId);
}

Tweet Comment::tweet() {
    TweetRepo _repo;
    return _repo.searchTweetById(_tweetId);
}
