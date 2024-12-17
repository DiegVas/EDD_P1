#include "avlNode.h"
#include "../../structs/actives/activeStruct.h"

avlNode::avlNode(activeStruct* activeValue): active(activeValue)
{
    this->active = activeValue;
    this->valor = activeValue->id;
    this->balanceF = 0;
    this->left = nullptr;
    this->right = nullptr;
}
