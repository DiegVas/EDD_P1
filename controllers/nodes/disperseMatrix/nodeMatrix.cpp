#include "nodeMatrix.h"

#include <algorithm>
#include <string>
#include "../../functions/toLowerCase.h"

nodeMatrix::nodeMatrix(std::string userName)
{
    this->front = nullptr;
    this->behind = nullptr;
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->prev = nullptr;

    // ! Inicializamos el nombre de usuario y convertir a minusculas

    this->userName = toLowerCase(userName);
};
