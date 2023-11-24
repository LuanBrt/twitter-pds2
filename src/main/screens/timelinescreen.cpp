#include "screens/timelinescreen.hpp"

void TimelineScreen::renderTweetList(std::vector<Tweet> tweets) {
    std::cout << "\nSeus tweets: \n\n";
    for (auto tweet : tweets) {
        std::cout << tweet.author().username() << " - " << tweet.description() << std::endl;
    }
}