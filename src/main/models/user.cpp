#include "models/user.hpp"

namespace model {
    int User::id() {
        return _id;
    }

    std::string User::username() {
        return _username;
    }

    std::string User::password() {
        return _password;
    }

    std::string User::nickname() {
        return _nickname;
    }
}
