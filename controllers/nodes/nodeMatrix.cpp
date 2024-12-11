#include "nodeMatrix.h"

nodeMatrix::nodeMatrix(const int value) {
    this->front = nullptr;
    this->behind = nullptr;
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->prev = nullptr;
    this->value = value;
};
