#include "screens/loginscreen.hpp"
#include <iostream>

LoginScreen::LoginScreen() {
    _title = "Menu de Autenticação";
}

void LoginScreen::successfulLogin(User authenticatedUser) {
    flushConsole();
    renderMessage("Login bem sucedido.");
    renderMessage("Bem-vindo, " + authenticatedUser.nickname() + ".");
    renderMessage("Direcionando para a timeline...");
};

void LoginScreen::sucessfulRegister(User registerUser) {
    flushConsole();
    renderMessage("Registro feito com sucesso!");
    renderMessage("O Usuário " + registerUser.username() + " foi criado!");
    renderMessage("Voltando para a página inicial....");
    renderMessage("\n");
}

