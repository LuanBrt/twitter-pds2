#pragma once

#include <map>
#include <string>
#include <vector>

class AbstractScreen {
    public:

        /// @brief Destrutor padrão
        virtual ~AbstractScreen() = default;
        

        /// @brief Mostra ao usuário as possíveis ações a serem tomadas
        /// @return A opção selecionada
        virtual int renderMenu(const std::map<int, std::string> &options) const;

        /// @brief Cria uma caixa de texto, onde o texto de apresentação é o valor do content
        /// @param content 
        /// @return O valor passado pelo usuário
        virtual std::string Input(std::string content);

        /// @brief Mostra ao usuário um formulário exigindo os campos selecionados
        /// @param fields 
        /// @return Um mapa representando o valor passado pelo usuário a cada campo
        virtual std::map<std::string, std::string> renderForm(std::vector<std::string> fields) const;

    protected:
        std::string _title;
};