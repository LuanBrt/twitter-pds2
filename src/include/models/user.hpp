#pragma once

#include <string>

class User {
public:
    User(std::string username, std::string password, std::string nickname): _username(username), _password(password), _nickname(nickname) {}
    User(int id, std::string username, std::string password, std::string nickname): _id(id), _username(username), _password(password), _nickname(nickname) {}
    int id();
    std::string username();
    std::string password();
    std::string nickname();
private:
    int _id;
    std::string _username;
    std::string _password;
    std::string _nickname;
};