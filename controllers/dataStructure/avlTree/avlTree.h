
#ifndef AVLTREE_H
#define AVLTREE_H
#include "../../nodes/avl/avlNode.h"


class avlTree{

public:
    avlNode *root;
    void insert(int value);
    void deleteNode(int value);
    avlTree();

private:
    // ? Metodo para insertar un nodo en el arbol
    void insertNode(avlNode *newNode, avlNode *&root);

    // ? Metodo para calcular la altura maxima
    int maxHeigth(avlNode *node);

    // ? Metodo para calcular el factor de balance ( alt(der)- alt(izq) )
    int balanceFactor(avlNode *node);

    // ? Asignar nuevo factor de balance a la raiz y sus nodos
    void assignBalance(avlNode *&node);

    // ? Metodo para rotar a la derecha
    void rotateRight(avlNode *&node);

    // ? Metodo para rotar a la izquierda
    void rotateLeft(avlNode *&node);

    // ? Metodo para rotar a la derecha y luego a la izquierda
    void rotateRightLeft(avlNode *&node);

    // ? Metodo para rotar a la izquierda y luego a la derecha
    void rotateLeftRight(avlNode *&node);

    // ? Metodo para eliminar un nodo
    void deleteNode(avlNode *&node, int value);

    avlNode *minValueNode(avlNode* &node);

    bool isSheet(avlNode *node);



};
#endif
