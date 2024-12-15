
#include "nodeMatrix.h"



nodeMatrix::nodeMatrix(const std::string userName)

{
    this->front = nullptr;
    this->behind = nullptr;
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->prev = nullptr;

    this->user = nullptr;
    this->userName = userName;
}
;

nodeMatrix::nodeMatrix(userStruct* user)
{
    this->front = nullptr;
    this->behind = nullptr;
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->prev = nullptr;

    this->user = user;
    this->userName = user->userName;
};
