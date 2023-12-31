#include "controllers/authcontroller.hpp"
#include "controllers/timelinecontroller.hpp"

// temp
#include "models/userrepo.hpp"
#include "models/user.hpp"
#include "models/tweetrepo.hpp"
#include "models/tweet.hpp"

#include <iostream>

namespace controller {
    /* Constructor:
    Objetivo: Inicializa o controlador de autenticação com opções padrão.
    Funcionalidades: Define opções para sair, entrar (login) e registrar. */
    AuthController::AuthController() {
        _options[ValidOptions::EXIT] = "Sair";
        _options[ValidOptions::LOGIN] = "Entrar";
        _options[ValidOptions::REGISTER] = "Registrar";
    }

    /* ValidateUser:
    Objetivo: Verifica se os dados fornecidos para registro são válidos.
    Funcionalidades: Verifica se os pré-requisitos para registro estão sendo atendido */

    bool AuthController::validateUser(std::map<std::string, std::string> possibleUser) {
        bool userExists = false;
        std::vector<model::User> dbResponse = _repo.searchUser(possibleUser["Usuario"]);

        for (auto user : dbResponse) {
            std::cout<<user.username()<<std::endl;
            
            if (user.username() == possibleUser["Usuario"]) {

            _loginScreen.renderMessage("Já existe um usuário com o mesmo nome!\n");
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

    /* ValidateLogin:
    Objetivo: Autentica um usuário com base nas credenciais fornecidas.
    Funcionalidades: Procura no banco de dados por um usuário com o nome de usuário fornecido.
    Retorna o objeto User se as credenciais coincidirem; caso contrário, retorna nullptr. */

    model::User* AuthController::validateLogin(std::map<std::string, std::string> possibleUser) {
        std::vector<model::User> dbResponse = _repo.searchUser(possibleUser["Usuario"]); 

        for (auto& user : dbResponse) {
            if (user.username() == possibleUser["Usuario"] && user.password() == possibleUser["Senha"]) {
                return new model::User(user);
            };
        }

        return nullptr;
    }

    /* Função render:
    Objetivo: Controla a interface de usuário para login, registro e saída.

    Funcionalidades: 
    Renderiza um menu com opções.
    Processa a escolha do usuário.
    Para o login bem-sucedido, redireciona para o TimelineController.
    Para o registro, realiza a validação e adiciona um novo usuário ao banco de dados.
    */

    AbstractController *AuthController::render() {
        int selected = _loginScreen.renderMenu(_options);
        switch (selected) { 
            
            // Sair
            case ValidOptions::EXIT: {
                exit(0);
                break;
            }
            
            // Obter credenciais de login:
            case ValidOptions::LOGIN: {
                _loginScreen.flushConsole();
                std::map<std::string, std::string> response = _loginScreen.renderForm({"Usuario", "Senha"});
                model::User* authenticatedUser = validateLogin(response);

                if (validateLogin(response) == nullptr) {
                    // LÓGICA DE LOGIN MAL SUCEDIDO:
                    _loginScreen.renderMessage("Login mal sucedido, voltando para a tela inicial....");
                    return new AuthController;

                }
                else {  
                    // LÓGICA DE LOGIN BEM SUCEDIDO:
                    _loginScreen.successfulLogin(*authenticatedUser);
                    return new TimelineController(*authenticatedUser);
                }
            }
            // Implementação da escolha REGISTER:
            case ValidOptions::REGISTER: {
                _loginScreen.flushConsole();
                std::map<std::string, std::string> response = _loginScreen.renderForm({"Usuario", "Apelido", "Senha", "Confirmação de Senha"});

                //Código a seguir é um feedback do registro, se ele foi bem ou mal sucedido:
                if(validateUser(response) == 1) {
                    model::User tempUser(response["Usuario"],response["Senha"],response["Apelido"]);

                    model::User registerUser = _repo.addUser(tempUser);
                    _loginScreen.sucessfulRegister(registerUser);
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
}