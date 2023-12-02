#include "screens/timelinescreen.hpp"

void TimelineScreen::renderTweetList(std::vector<Tweet> tweets) {
    std::cout << "\nSeus tweets: \n\n";
    for (auto tweet : tweets) {
        std::cout << tweet.author().username() << " - " << tweet.description() << std::endl;
    }
}

void TimelineScreen::renderTextSearchUser(std::vector<User> users){

    if(users.empty()){

        std::cout<<"Desculpe, mas não encotramos nenhum usuário"<<std::endl;

    }else{

        for(auto it: users){

            std::cout<<it.username()<<std::endl<<it.nickname()<<std::endl;

        }

    }

}