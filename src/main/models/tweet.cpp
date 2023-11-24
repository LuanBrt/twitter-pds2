#include "models/tweet.hpp"
#include "models/comment.hpp"
#include "models/userrepo.hpp"
#include "models/user.hpp"


int Tweet::id(){
  return _id;
}

User Tweet::author() {
    UserRepo _repo;
    return _repo.searchUserById(_authorId);
}

std::string Tweet::description() {
    return _description;
}

std::string Tweet::timestamp() {
    return _timestamp;
}

int Tweet::likes() {
    return _likes;
}

Tweet Tweet::getTweetById(int id, std::vector<Tweet> tweets) {
    for (auto tweet : tweets) {
        if (tweet.id() == id) {
            return tweet;
        }
    }

    // Se não encontrar, retorna um tweet "vazio" (os atributos não são garantidos)
    return Tweet(-1, -1, "", "", 0);
}