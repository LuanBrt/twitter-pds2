#pragma once

#include "controllers/abstractcontroller.hpp"

class CommandLine {
    public:
        /// @brief Comando utilizado para rodar a aplicação
        void run();
    private:
        AbstractController *_controller;
};