//
// Created by HP on 06/12/2024.
//

#ifndef NODEMATRIX_H
#define NODEMATRIX_H

class nodeMatrix {
public:
    int value;

    nodeMatrix* front;
    nodeMatrix* behind;
    nodeMatrix* up;
    nodeMatrix* down;

    nodeMatrix* next;
    nodeMatrix* prev;

    explicit nodeMatrix(int value);

};

#endif //NODEMATRIX_H
