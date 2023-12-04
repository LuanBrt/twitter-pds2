#include "controllers/userprofilecontroller.hpp"
#include "controllers/timelinecontroller.hpp"

#include <iostream>
#include <map>
#include <string>
#include <ctime>
 
UserProfileController::UserProfileController(User user, User loggedUser)
    : _user(user), _loggedUser(loggedUser) { 
    _isFollowed = false;
    bool isYourself = false;
    if(_userRepo.isUserFollow(loggedUser, user)) _isFollowed = true;
    if (_loggedUser.id() == _user.id()) isYourself = true;

    _options[ValidOptions::EXIT] = "Sair para timeline";
    ((isYourself) ? "" : _options[ValidOptions::FOLLOWUSER] = (_isFollowed) ? ("Deixar de seguir " + user.username()) : ("Seguir " + user.username()));
}

AbstractController *UserProfileController::render() {
    _userProfileScreen.flushConsole();
    getUser();
    int option = _userProfileScreen.renderMenu(_options);
    switch (option) {
        // Sair:
        case EXIT: {
            return nullptr;
        };
        case FOLLOWUSER: {
            followUser();
            UserProfileController(_user, _loggedUser).render();
        };
    }
    return nullptr;
}

void UserProfileController::getUser() {
    std::vector<Tweet> response = _tweetRepo.getUserTimeline(_user);
    _userProfileScreen.renderUser(_user, response.size());
    _timelineScreen.renderSeparator();
    _timelineScreen.renderTweetList(response);
}

void UserProfileController::followUser() {
    if (!_isFollowed) {
        User userFollowed = _userRepo.followUser(_loggedUser, _user);
    } else {
        _userRepo.unfollowUser(_loggedUser, _user);
    }
}

