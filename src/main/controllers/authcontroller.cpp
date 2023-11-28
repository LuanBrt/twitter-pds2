#include "controllers/authcontroller.hpp"
#include "controllers/timelinecontroller.hpp"

// temp
#include "models/userrepo.hpp"
#include "models/user.hpp"
#include "models/tweetrepo.hpp"
#include "models/tweet.hpp"


#include <iostream>

AuthController::AuthController() {
    _options[ValidOptions::EXIT] = "Sair";
    _options[ValidOptions::LOGIN] = "Entrar";
    _options[ValidOptions::REGISTER] = "Registrar";
}

//FUNCAO QUE VALIDA /
bool AuthController::validateUser(std::map<std::string, std::string> possibleUser) {
    bool userExists = false;
    std::vector<User> dbResponse = _repo.searchUser(possibleUser["Usuario"]);

    for (auto user : dbResponse) {
        std::cout<<user.username()<<std::endl;
        
        if (user.username() == possibleUser["Usuario"]) {

        std::cout<<"Já existe com o mesmo nome, portanto Não era pra criar!"<<std::endl;
            userExists = true;
        };
    }

    if (possibleUser["Apelido"] == "" ||
        possibleUser["Usuario"] == "" ||
        possibleUser["Senha"] == "" ||
        possibleUser["Confirmação de Senha"] == "" ||
        possibleUser["Senha"].size() < 8 ||
        possibleUser["Senha"] != possibleUser["Confirmação de Senha"] ||
        userExists == true) {
        return false;  // Se alguma verificação falhar, retorna falso
    }
    return true;

};

// FUNÇÃO PRECISANDO DE CONSERTO:
User* AuthController::validateLogin(std::map<std::string, std::string> possibleUser) {
    std::vector<User> dbResponse = _repo.searchUser(possibleUser["Usuario"]); 

    for ( auto& user : dbResponse) {
        if (user.username() == possibleUser["Usuario"] && user.password() == possibleUser["Senha"]) {
            return new User(user);
        };
    }

    return nullptr;
}



AbstractController *AuthController::render() {
    int selected = _loginScreen.renderMenu(_options);
    switch (selected) { 
        
        // Sair
        case ValidOptions::EXIT: {
            exit(0);
            break;
        }
        
        // Obter credenciais de login
        case ValidOptions::LOGIN: {

            std::map<std::string, std::string> response = _loginScreen.renderForm({"Usuario", "Senha"});
            User* authenticatedUser = validateLogin(response);

            if (validateLogin(response) == nullptr) {
                // LÓGICA DE LOGIN MAL SUCEDIDO
                _loginScreen.renderMessage("Login mal sucedido, voltando para a tela inicial....");
                //SOCORRO
                return new AuthController;

            }
            else {  
                _loginScreen.renderMessage("Login bem sucedido.");
                _loginScreen.renderMessage("Bem-vindo, " + authenticatedUser->nickname() + ".");
                _loginScreen.renderMessage("Direcionando para a timeline...");
                _loginScreen.renderMessage("\n");
                return new TimelineController(*authenticatedUser);
            }
        }
        // Register
        case ValidOptions::REGISTER: {
            std::map<std::string, std::string> response = _loginScreen.renderForm({"Usuario", "Apelido", "Senha", "Confirmação de Senha"});

            //O CÓDIGO A SEGUIR SÃO FORMAS DE TESTAR OS CRITÉRIOS DE REGISTRO.
            if(validateUser(response) == 1) {

                User tempUser(response["Usuario"],response["Senha"],response["Apelido"]);

                User newUser = _repo.addUser(tempUser);

                _loginScreen.renderMessage("Registro feito com sucesso!");
                _loginScreen.renderMessage("O Usuário " + newUser.username() + " foi criado!");
                _loginScreen.renderMessage("Voltando para a página inicial....");
                _loginScreen.renderMessage("\n");

            }
            else {
                _loginScreen.renderMessage("Dados para registro inválidos");
                _loginScreen.renderMessage("Voltando para a página inicial...");
            }
        }
        return new AuthController;
    }
    return nullptr;
}