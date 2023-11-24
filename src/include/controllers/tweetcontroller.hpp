#pragma once

#include "controllers/abstractcontroller.hpp"
#include "screens/tweetscreen.hpp"


#include <map>

class TweetController: public AbstractController {
public:
    TweetController();
    AbstractController *render() override;
private:
    enum ValidOptions {
        EXIT,
        LIKE,
        RETWEET,
        COMMENT, 
    };
    std::map<int, std::string> _options;
    TweetScreen _tweetScreen;

};