
#include "nodeMatrix.h"

#include <algorithm>


nodeMatrix::nodeMatrix(const std::string userName)

{
    this->front = nullptr;
    this->behind = nullptr;
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
    this->user = nullptr;

    std::string modifiedUserName = userName; // Make a copy of the string
    std::replace(modifiedUserName.begin(), modifiedUserName.end(), ' ', '_');

    this->userName = modifiedUserName;
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
