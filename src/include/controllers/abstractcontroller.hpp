#pragma once

#include "screens/abstractscreen.hpp"

namespace controller {
    class AbstractController {
        public:
            /// @brief Destrutor padrão
            virtual ~AbstractController() = default;

            /// @brief Funcao utilizada para renderizar uma view, obter input dela, e passar pro proximo controller
            /// @return Proximo controller a ser acessado
            virtual AbstractController *render() = 0;
    };
}