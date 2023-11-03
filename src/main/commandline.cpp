#include "commandline.hpp"
#include "controllers/authcontroller.hpp"

void CommandLine::run() {
    _controller = new AuthController;

    while (_controller != nullptr) {
        AbstractController* old_controller = _controller;
        _controller = _controller->render();

        delete old_controller;
    }
}