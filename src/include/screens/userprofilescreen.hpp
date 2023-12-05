#pragma once

#include "screens/abstractscreen.hpp"
#include "models/user.hpp"

#include <iostream>
#include <vector>

namespace screen {
    class UserProfileScreen : public AbstractScreen {
    public:
        void renderUser(model::User u, int numberTweets);
    };
}