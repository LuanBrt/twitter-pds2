#include "models/comment.hpp"
#include "models/tweet.hpp"
#include "models/user.hpp"
#include "models/userrepo.hpp"
#include "models/tweetrepo.hpp"

namespace model {
    // retorna o ID do comentário
    int Comment::id() {
        return _id;
    }

    // retorna a descrição do comentário
    std::string Comment::description() {
        return _description;
    }

    // Retorna o autor do comentário, obtido através de uma consulta ao repositório de usuários (UserRepo) com base no identificador do autor (_authorId)
    User Comment::author() {
        repo::UserRepo _repo;
        return _repo.searchUserById(_authorId);
    }

    // Retorna o tweet ao qual o comentário está vinculado, obtido através de uma consulta ao repositório de tweets (TweetRepo) com base no identificador do tweet (_tweetId)
    Tweet Comment::tweet() {
        repo::TweetRepo _repo;
        return _repo.searchTweetById(_tweetId);
    }
}