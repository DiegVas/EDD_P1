

#ifndef NODEMATRIX_H
#define NODEMATRIX_H
#include <string>

class nodeMatrix {
public:
    std::string userName;

    nodeMatrix *front;
    nodeMatrix *behind;
    nodeMatrix *up;
    nodeMatrix *down;

    nodeMatrix *next;
    nodeMatrix *prev;

    explicit nodeMatrix(std::string userName);
};

#endif //NODEMATRIX_H
