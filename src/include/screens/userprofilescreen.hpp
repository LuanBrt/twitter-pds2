#pragma once

#include "screens/abstractscreen.hpp"
#include "models/user.hpp"

#include <iostream>
#include <vector>

class UserProfileScreen : public AbstractScreen {
public:
    void renderUser(User u, int numberTweets);
};