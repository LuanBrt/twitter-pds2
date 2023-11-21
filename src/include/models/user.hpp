#pragma once

#include <string>

class User {
public:
    User(std::string username, std::string password, std::string nickname): _username(username), _password(password), _nickname(nickname) {}
    std::string username();
    std::string password();
    std::string nickname();
private:
    std::string _username;
    std::string _password;
    std::string _nickname;
};