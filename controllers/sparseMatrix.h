//
// Created by HP on 06/12/2024.
//

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <string>
#include "nodes/nodeMatrix.h"


class sparse_Matrix {
public:
    // ! Cabezeras de la matriz dispersa
    nodeMatrix *headerH;
    nodeMatrix *headerV;

    sparse_Matrix();

    // ! Metodos de la matriz dispersa

    // ? Metodo para verificar si la matriz esta vacia
    bool isEmpy() const;

    // ? Metodos para crear una cabezera horizontal nodo en la matriz dispersa
    nodeMatrix *getHeaderH(int value) const;

    nodeMatrix *getHeaderV(int value) const;

    // ? Metodos para insertar cabezeras en la matriz dispersa
    nodeMatrix *insertHeaderH(int value);

    nodeMatrix *insertHeaderV(int value);

    void insertHeaders(int value, int headerH, int headerV);

    // ? Metodo para insertar un nodo en la matriz dispersa

    // ! Solo si en algun caso esta al final de una cabezera horizontal y vertical
    void insertFinal(nodeMatrix *value, nodeMatrix *headerH, nodeMatrix *headerV);

    void insertFinalH(nodeMatrix *value, nodeMatrix *headerH);

    void insertFinalV(nodeMatrix *value, nodeMatrix *headerV);

    void insertMiddleV(nodeMatrix *value, nodeMatrix *headerV);

    void insertMiddleH(nodeMatrix *value, nodeMatrix *headerH);


    // ? Metodo para encontrar la ubicacion de la cabezera
    nodeMatrix *findHeaderH(nodeMatrix *headerH) const;

    nodeMatrix *findHeaderV(nodeMatrix *headerH) const;

    bool moreDown(nodeMatrix *headerV, int headderValue) const;

    bool moreRight(nodeMatrix *headerH, int headderValue) const;
};


#endif //SPARSEMATRIX_H
