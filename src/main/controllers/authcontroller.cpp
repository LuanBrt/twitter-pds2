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
bool AuthController::validateUser(std::map<std::string, std::string> PossibleUser) {
    //if(PossibleUser["Usuario"] == /* Lógica para verificar se usuario já existe no banco de dados */ ) {

    //}
    if (PossibleUser["Apelido"] == "") return 0;
    if (PossibleUser["Usuario"] == "") return 0;
    if (PossibleUser["Senha"] == "") return 0;
    if (PossibleUser["Confirmação de Senha"] == "") return 0;
    if (PossibleUser["Senha"].size() < 8) return 0;
    if (PossibleUser["Senha"] != PossibleUser["Confirmação de Senha"]) return 0;
    else return 1;

};


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
            UserRepo userRepo;
            TweetRepo tweetRepo;
            User r1 = userRepo.addUser(User("luan", "123456", "Luan Borges"));
            User r2 = userRepo.addUser(User("marquezintop", "123456", "Marquez"));
            userRepo.followUser(r1, r2);
            Tweet tweet1(r2.id(), "teste tweet", "2023", 0);
            Tweet tweet2(r1.id(), "meu tweet", "2023", 0);

            tweetRepo.addTweet(tweet1);
            tweetRepo.addTweet(tweet2);


            return new TimelineController(r1);
        }

        // Register
        case ValidOptions::REGISTER: {
            std::map<std::string, std::string> response = _loginScreen.renderForm({"Usuario", "Apelido", "Senha", "Confirmação de Senha"});
            //O CÓDIGO A SEGUIR SÃO FORMAS DE TESTAR OS CRITÉRIOS DE REGISTRO, A IMPLEMENTAÇÃO DA VIEW NÃO DEVE JAMAIS SER FEITA NESTE ARQUIVO.
            if(validateUser(response) == 1) {
                std::cout<<"Registro feito com sucesso!\n";
                std::cout<<"Voltando para a página de login\n";
            }
            else {
                std::cout<<"Dados para registro inválidos\n";
                std::cout<<"Voltando para a página inicial...\n";
                selected = _loginScreen.renderMenu(_options);
            }

        }
    }
    return nullptr;
}