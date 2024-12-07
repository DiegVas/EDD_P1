
#include "sparseMatrix.h"
#include "nodes/nodeMatrix.h"

sparse_Matrix::sparse_Matrix() {
    this->headerH = nullptr;
    this->headerV = nullptr;
}

bool sparse_Matrix::isEmpy() const {
    return this -> headerH == nullptr && this -> headerV == nullptr;
}

// ? Metodo para obtener una cabezera horizontal nodo en la matriz dispersa
nodeMatrix *sparse_Matrix::getHeaderH(int value) const {

    if (isEmpy()) return  nullptr;

    nodeMatrix *aux = headerH;

    while (aux->next != nullptr) {
        if (aux -> value == value) {
            return aux;
        }
        aux = aux -> next;
    }

    return nullptr;
}

// ? Metodo para obtener una cabezera vertical nodo en la matriz dispersa
nodeMatrix *sparse_Matrix::getHeaderV(const int value) const {

    if (isEmpy()) return  nullptr;

    nodeMatrix *aux = headerV;

    while (aux->down != nullptr) {
        if (aux -> value == value) {
            return aux;
        }
        aux = aux -> down;
    }

    return nullptr;
}

// ? Metodos para insertar cabezeras horizontale en la matriz dispersa
nodeMatrix * sparse_Matrix::insertHeaderH(int value) {
    nodeMatrix *newNode = new nodeMatrix(value);

    // ! Si la matriz esta vacia
    if (headerH == nullptr) {
        headerH = newNode;
        return newNode;
    }

    nodeMatrix *aux = headerH;

    while (aux -> next != nullptr) {
        aux = aux -> next;
    }

    aux -> next = newNode;
    newNode -> prev = aux;

    return newNode;

}

// ? Metodos para insertar cabezeras verticales en la matriz dispersa
nodeMatrix * sparse_Matrix::insertHeaderV(const int value) {
    nodeMatrix *newNode = new nodeMatrix(value);

    // ! Si la matriz esta vacia
    if (headerV == nullptr) {
        headerV = newNode;
        return newNode;
    }

    nodeMatrix *aux = headerV;

    while (aux -> down != nullptr) {
        aux = aux -> down;
    }

    aux -> down = newNode;
    newNode -> up = aux;

    return newNode;
}

// ? Metodo para iniciar  cabezeras en la matriz dispersa
nodeMatrix * sparse_Matrix::insertHeaders(int value, int headerH, int headerV) {
    if (isEmpy()) {
       nodeMatrix *headH = insertHeaderH(headerH);
       nodeMatrix *headV = insertHeaderV(headerV);
        insertFinal(value, headH, headV);
    }
}

nodeMatrix * sparse_Matrix::insertFinal(int value, nodeMatrix *headerH, nodeMatrix *headerV) {
    nodeMatrix *newUser = new nodeMatrix(value);

    nodeMatrix *auxH = headerH;
    nodeMatrix *auxV = headerV;

    while (auxH->down != nullptr) {
        auxH = auxH->down;
    }

    auxH->down = newUser;
    newUser->up = auxH;

    while (auxV->next != nullptr) {
        auxV = auxV->next;
    }

    auxV->next = newUser;
    newUser->prev = auxV;

}

// ? Metodo para insertar nodos en la matriz dispersa
// ! Solo si la matriz esta vacia






