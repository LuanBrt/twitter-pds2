#pragma once
#include <iostream>
#include <map>
#include <string>
#include "screens/usersearch.hpp"
#include "controllers/abstractcontroller.hpp"

class userSearchController::public abstractcontroller{

    public:
        userSearchController();
        AbstractController *render() override;
    
    protected:
        std::map<int, std::string>field;
        std::string results;
        userSearch _usersearch;

};