

#ifndef AVLNODE_H
#define AVLNODE_H
#include "../../structs/actives/activeStruct.h"


class avlNode {

  public:
    std::string valor;
    int balanceF;
    avlNode *left;
    avlNode *right;
    activeStruct* active;
    avlNode(activeStruct* activeValue);
};

#endif //AVLNODE_H
