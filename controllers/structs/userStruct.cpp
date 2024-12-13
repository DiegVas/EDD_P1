#include "userStruct.h"
#include <iostream>

void userStruct::imprimirInfo() const {
    std::cout << "Nombre: " << userName << "," << ", Nombre completo: " << fullName << "," << "Contraseña: " << password << std::endl;
}