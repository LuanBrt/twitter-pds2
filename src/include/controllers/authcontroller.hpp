#pragma once

#include "controllers/abstractcontroller.hpp"
#include "screens/loginscreen.hpp"
#include "models/userrepo.hpp"

#include <string>
#include <map>

namespace controller {
    class AuthController: public AbstractController {
        public:
            /// @brief Construtor padrao
            AuthController();
            /// @brief Renderiza uma tela para o usuario e obtem inputs do mesmo
            /// @return Novo controlador de uma nova tela
            AbstractController *render() override;

            /// @brief Função que valida os dados fornecidos para o registro de um novo usuário.
            /// @param  possibleUser: "Mapa-resposta" dos campos do formulário de registro de usuário para seus valores correspondentes (usuario, apelido, senha, confirmação de senha).
            /// @return Retorna verdadeiro se os dados forem válidos e o registro puder ser concluído com sucesso. Retorna falso se houver problemas com os dados fornecidos.
            bool validateUser(std::map<std::string, std::string> possibleUser);

            /// @brief Função que valida as credenciais de login de um usuário.
            /// @param  possibleUser: "Mapa-resposta" dos campos do formulário de login de usuário para seus valores correspondentes (usuario, apelido, senha).
            /// @return Retorna um ponteiro para o objeto User autenticado se as credenciais estiverem corretas. Retorna nullptr se as credenciais forem inválidas.
            model::User* validateLogin(std::map<std::string, std::string> possibleUser);

        private:

            // Enum com as opções do formulário do menu de autenticação:
            enum ValidOptions {
                EXIT,
                LOGIN,
                REGISTER, 
            };
            std::map<int, std::string> _options;

            screen::LoginScreen _loginScreen;
            repo::UserRepo _repo;
    };
}