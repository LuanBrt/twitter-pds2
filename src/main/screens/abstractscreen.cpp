#include "screens/abstractscreen.hpp"

#include <iostream>

int checkStoiFunction(std::string num) {
    int numResult;
    try {
        numResult = stoi(num);
    } catch (const std::invalid_argument &e) {
        return -1;
    }
    return numResult;
}

int AbstractScreen::renderMenu(const std::map<int, std::string> &options) const {
    std::string selected;
    std::cout << _title << std::endl;
    for (auto option : options) {
        std::cout << option.first << " - " << option.second << std::endl;
    }
    std::cout << "\n: ";

    int selectedNum;
    do {
        std::cin >> selected;
        selectedNum = checkStoiFunction(selected);
        if(selectedNum == -1) renderMessage("Digite um número corretamente\n");
    } while (selectedNum < 0);

    return selectedNum;
}

std::map<std::string, std::string> AbstractScreen::renderForm(std::vector<std::string> fields) const {
    std::map<std::string, std::string> response;

    for (auto field : fields) {
        std::string value;
        std::cout << field << " : ";

        std::getline(std::cin >> std::ws, value);
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