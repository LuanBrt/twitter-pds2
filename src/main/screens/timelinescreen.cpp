#include "screens/timelinescreen.hpp"

namespace screen {
    void TimelineScreen::renderTweetList(std::vector<model::Tweet> tweets) {
        std::cout << "\nSeus tweets: \n\n";
        for (auto tweet : tweets) {
            std::cout << tweet.author().username() << " - " << tweet.description() << std::endl;
        }
    }

    void TimelineScreen::renderTextSearchUser(std::vector<model::User> users){

        if(users.empty()){

            std::cout<<"Desculpe, mas não encotramos nenhum usuário"<<std::endl;

        }else{

            for(auto it: users){

                std::cout<<it.username()<<std::endl<<it.nickname()<<std::endl;

            }

        }

    }
}