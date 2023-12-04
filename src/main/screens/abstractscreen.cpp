#include "screens/abstractscreen.hpp"

#include <iostream>

namespace screen {
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

    std::map<std::string, std::string> AbstractScreen::renderForm(std::vector<std::string> fields) const {
        std::map<std::string, std::string> response;

        for (auto field : fields) {
            std::string value;
            std::cout << field << " : ";
            std::cin.ignore();

            std::getline(std::cin, value);
            response[field] = value;    
        }

        return response;
    }

    // Função que renderiza uma mensagem na tela:
    void AbstractScreen::renderMessage(std::string message) const{
        std::cout << message << std::endl;
    }

    // Função que limpa a tela:
    void AbstractScreen::flushConsole() const{
        system("clear");
    }

    void AbstractScreen::renderSeparator() const{
        std::cout << std::endl << "=====================================================" << std::endl;
    }
}