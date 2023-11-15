#include "controllers/usersearchcontroller.hpp"
#include "controllers/abstractcontroller.hpp"
#include <iostream>
#include <map>
#include <string>

AbstractController *userSearchcontrolle::render(){

    field[1] = "Buscar Usuário";
    int selected = _searchuser.render(field);

}