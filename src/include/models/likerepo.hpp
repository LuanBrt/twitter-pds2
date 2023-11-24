#pragma once

#include "models/abstractrepo.hpp"

#include <string>
#include <vector>

class LikeRepo : public AbstractRepo {
public:

    void addLike(int userId, int tweetId);

    int searchLikeByUserId(int userId, int tweetId);

    void deleteLike(int userId, int tweetId);
};