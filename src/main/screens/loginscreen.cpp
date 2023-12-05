#include "screens/loginscreen.hpp"
#include <iostream>

namespace screen {
    LoginScreen::LoginScreen() {
        _title = "Menu de Autenticação";
    }

    void LoginScreen::successfulLogin(model::User authenticatedUser) {
        flushConsole();
        renderMessage("Login bem sucedido.");
        renderMessage("Bem-vindo, " + authenticatedUser.nickname() + ".");
        renderMessage("Direcionando para a timeline...");
    };

    void LoginScreen::sucessfulRegister(model::User registerUser) {
        flushConsole();
        renderMessage("Registro feito com sucesso!");
        renderMessage("O Usuário " + registerUser.username() + " foi criado!");
        renderMessage("Voltando para a página inicial....");
        renderMessage("\n");
    }
}