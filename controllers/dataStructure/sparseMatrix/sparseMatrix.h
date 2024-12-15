//
// Created by HP on 06/12/2024.
//

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <string>
#include "../../nodes/disperseMatrix/nodeMatrix.h"
#include "../../structs/userStruct.h"


class sparse_Matrix
{
public:
    // ! Cabezeras de la matriz dispersa
    nodeMatrix* headerH;
    nodeMatrix* headerV;

    sparse_Matrix();

    // ! Metodos de la matriz dispersa

    // ? Metodo para verificar si la matriz esta vacia
    bool isEmpy() const;

    // ? Metodos para crear una cabezera horizontal nodo en la matriz dispersa
    nodeMatrix* getHeaderH(std::string value) const;

    nodeMatrix* getHeaderV(std::string value) const;

    // ? Metodos para insertar cabezeras en la matriz dispersa
    nodeMatrix* insertHeaderH(std::string value);

    nodeMatrix* insertHeaderV(std::string value);

    // ? Metodo para insertar un nodo en la matriz dispersa
    int insertHeaders(userStruct& user);

    // ? Solo si en algun caso esta al final de una cabezera horizontal y vertical
    static void insertFinal(nodeMatrix* value, nodeMatrix* headerH, nodeMatrix* headerV);

    // ? Solo si en algun caso esta al final de una cabezera horizontal o vertial
    static void insertFinalH(nodeMatrix* value, nodeMatrix* headerH);

    static void insertFinalV(nodeMatrix* value, nodeMatrix* headerV);

    // ? Solo si en algun caso esta en medio de una cabezera vertical o horizontal
    static void insertMiddleV(nodeMatrix* value, nodeMatrix* headerV);

    static void insertMiddleH(nodeMatrix* value, nodeMatrix* headerH);

    // ? Metodo para encontrar la ubicacion de la cabezera
    static nodeMatrix* findHeaderH(nodeMatrix* headerH);

    static nodeMatrix* findHeaderV(nodeMatrix* headerH);

    // ? Metodo para verificar si hay mas nodos hacia abajo o derecha
    static bool moreDown(nodeMatrix* headerV, const std::string& headderValue);

    static bool moreRight(nodeMatrix* headerH, const std::string& headderValue);

    // ? Metodo para verificar si la celda esta ocupada
    nodeMatrix* isOccupied(nodeMatrix* headerH, nodeMatrix* headerV);

    // ? Metdo para insertar atras de un nodo
    static int insertBehind(nodeMatrix* newNode, nodeMatrix* firstNode);

    nodeMatrix* searchNode(const userStruct& user);
};


#endif //SPARSEMATRIX_H
