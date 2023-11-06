#pragma once

#include <string>

class User {
public:
    std::string username();
    std::string password();
    std::string nickname();
    int followers();
private:
    std::string _username;
    std::string _password;
    std::string _nickname;
    int _followers;
};