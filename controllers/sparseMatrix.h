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
    nodeMatrix *getHeaderH(std::string value) const;

    nodeMatrix *getHeaderV(std::string value) const;

    // ? Metodos para insertar cabezeras en la matriz dispersa
    nodeMatrix *insertHeaderH(std::string value);

    nodeMatrix *insertHeaderV(std::string value);

    void insertHeaders(std::string value, std::string headerH, std::string headerV);

    // ? Metodo para insertar un nodo en la matriz dispersa

    // ! Solo si en algun caso esta al final de una cabezera horizontal y vertical
    static void insertFinal(nodeMatrix *value, nodeMatrix *headerH, nodeMatrix *headerV);

    static void insertFinalH(nodeMatrix *value, nodeMatrix *headerH);

    static void insertFinalV(nodeMatrix *value, nodeMatrix *headerV);

    static void insertMiddleV(nodeMatrix *value, nodeMatrix *headerV);

    static void insertMiddleH(nodeMatrix *value, nodeMatrix *headerH);


    // ? Metodo para encontrar la ubicacion de la cabezera
    static nodeMatrix *findHeaderH(nodeMatrix *headerH);

    static nodeMatrix *findHeaderV(nodeMatrix *headerH);

    static bool moreDown(nodeMatrix *headerV, std::string headderValue);

    static bool moreRight(nodeMatrix *headerH, std::string headderValue);
};


#endif //SPARSEMATRIX_H
