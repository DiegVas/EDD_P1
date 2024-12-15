//
// Created by HP on 12/12/2024.
//

#ifndef AVLNODE_H
#define AVLNODE_H


class avlNode {

  public:
    int valor;
    int balanceF;
    avlNode *left;
    avlNode *right;
    avlNode(int valor);
};

#endif //AVLNODE_H
