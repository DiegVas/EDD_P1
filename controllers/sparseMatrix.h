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

    // ? Metodos para obtener una cabezera horizontal nodo en la matriz dispersa
    nodeMatrix *getHeaderH(int value) const;
    nodeMatrix *getHeaderV(int value) const;

    // ? Metodos para insertar cabezeras en la matriz dispersa
    nodeMatrix *insertHeaderH(int value);
    nodeMatrix *insertHeaderV(int value);
    nodeMatrix *insertHeaders(int value, int headerH, int headerV);

    // ? Metodo para insertar un nodo en la matriz dispersa

    // ! Solo si la matriz esta vacia
    nodeMatrix *insertFinal(int value, nodeMatrix *headerH, nodeMatrix *headerV);




};

#endif //SPARSEMATRIX_H
