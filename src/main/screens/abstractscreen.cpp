#include "screens/abstractscreen.hpp"

#include <iostream>

int AbstractScreen::renderMenu(const std::map<int, std::string> &options) const {
    int selected;
    std::cout << _title << std::endl;
    for (auto option : options) {
        std::cout << option.first << " - " << option.second << std::endl;
    }
    std::cout << "\n: ";
    std::cin >> selected;

    return selected;
}


std::map<std::string, std::string> AbstractScreen::renderForm(std::vector<std::string> fields) const
{
    std::map<std::string, std::string> response;

    for (auto field : fields) {
        std::string value;
        std::cout << field << " : ";
        std::cin >> value;
        response[field] = value;
    }

    return response;
}