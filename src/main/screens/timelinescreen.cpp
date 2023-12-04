#include "screens/timelinescreen.hpp"

void TimelineScreen::renderTweetList(std::vector<Tweet> tweets) {
    renderMessage("\nTimeline: \n");
    for (auto tweet : tweets) {
        renderMessage("Id: " + std::to_string(tweet.id()));
        renderMessage(tweet.author().username() + " - " + tweet.description());
    }
}

void TimelineScreen::renderSearchUserResult(std::vector<User> users){
    flushConsole();
    renderSeparator();
    if (users.size() == 0) {
        renderMessage("Desculpe, mas não encotramos nenhum usuário");
    } else {
    renderMessage("Usuários Encontrados:");
    renderMessage("");
    for (auto user : users) {
        renderMessage(user.username());
    }
    renderSeparator();
    renderMessage("timeline");
    }
}