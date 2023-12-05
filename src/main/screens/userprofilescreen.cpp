#include "screens/userprofilescreen.hpp"

namespace screen {
    void UserProfileScreen::renderUser(model::User u, int numberTweets) {
        renderMessage("\nUsuário:" + u.username());
        renderMessage("Nickaname: " + u.nickname());
        if (numberTweets) renderMessage("Esse usuário já fez " + std::to_string(numberTweets) + " tweets na comunidade\n");
    }
}