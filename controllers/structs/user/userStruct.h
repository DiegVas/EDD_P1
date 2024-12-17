#ifndef USERSTRUCT_H
#define USERSTRUCT_H

#include "../../dataStructure/avlTree/avlTree.h"

struct userStruct {
public:
    std::string userName;
    std::string fullName;
    std::string password;
    std::string company;
    std::string country;
    std::string cell;
    linkedList *rentActives;

    // AVL tree activos
    avlTree *actives;
    userStruct(std::string userName, std::string fullName, std::string password, std::string company, std::string country);
};

#endif // USERSTRUCT_H