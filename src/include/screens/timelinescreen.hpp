#pragma once

#include "screens/abstractscreen.hpp"
#include "models/tweet.hpp"

#include <iostream>
#include <vector>

class TimelineScreen : public AbstractScreen {
public:
    /// @brief renderiza uma lista de tweets na tela
    /// @param tweets 
    void renderTweetList(std::vector<Tweet> tweets);

    /// @brief renderiza os dados dos usuários encontrados
    /// @param users 
    void renderTextSearchUser(std::vector<User> users);
};