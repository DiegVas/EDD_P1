//
// Created by HP on 16/12/2024.
//

#ifndef NODELINKED_H
#define NODELINKED_H
#include "../../structs/actives/activeStruct.h"


class nodeLinked {
public:
    activeStruct* active;
    nodeLinked* next;

    nodeLinked(activeStruct *active) : active(active), next(nullptr){};
};

#endif //NODELINKED_H
