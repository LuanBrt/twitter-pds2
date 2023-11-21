#pragma once

#include "screens/abstractscreen.hpp"
#include "models/tweet.hpp"

#include <vector>
#include <string>

class TweetScreen : public AbstractScreen {
    public:
        TweetScreen();
        void renderTweet(Tweet tweet);
};