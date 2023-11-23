#include "commandline.hpp"
#include "controllers/authcontroller.hpp"

void CommandLine::run() {
    _controller = new AuthController;

    // O programa executa até que a proxima tela de redirecionamento seja nula
    while (_controller != nullptr) {
        AbstractController* old_controller = _controller;
        // Renderizando o proximo controller
        _controller = _controller->render();

        // Deletando o controller que nao será mais utilizado
        delete old_controller;
    }
}