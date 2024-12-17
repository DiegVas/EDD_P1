

#ifndef NODEMATRIX_H
#define NODEMATRIX_H
#include <string>
#include "../../structs/user/userStruct.h"

class nodeMatrix
{
public:
    std::string userName;

    userStruct* user;

    nodeMatrix* front;
    nodeMatrix* behind;

    nodeMatrix* up;
    nodeMatrix* down;

    nodeMatrix* next;
    nodeMatrix* prev;

    nodeMatrix(const std::string userName);
    nodeMatrix(userStruct* user);
};

#endif //NODEMATRIX_H
