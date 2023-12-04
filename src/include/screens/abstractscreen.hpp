#pragma once

#include <map>
#include <string>
#include <vector>

namespace screen {
    class AbstractScreen {
        public:
            /// @brief Destrutor padrão
            virtual ~AbstractScreen() = default;

            /// @brief Mostra ao usuário as possíveis ações a serem tomadas
            /// @return A opção selecionada
            virtual int renderMenu(const std::map<int, std::string> &options) const;

            /// @brief Mostra ao usuário um formulário exigindo os campos selecionados
            /// @param fields 
            /// @return Um mapa representando o valor passado pelo usuário a cada campo
            virtual std::map<std::string, std::string> renderForm(std::vector<std::string> fields) const;
            virtual void renderMessage(std::string message) const;
            virtual void flushConsole() const;
            virtual void renderSeparator() const;
    
        protected:
            std::string _title;
    };
}