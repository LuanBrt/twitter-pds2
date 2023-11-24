#pragma once

#include "controllers/abstractcontroller.hpp"

class TimelineController: public AbstractController {
public:
    AbstractController(User u);
    AbstractController *render() override;
private:
    User user;
    TimelineScreen _view;
    TweetRepo _repo;
}