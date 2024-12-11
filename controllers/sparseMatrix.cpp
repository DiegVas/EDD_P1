
#include "sparseMatrix.h"
#include "nodes/nodeMatrix.h"

sparse_Matrix::sparse_Matrix() {
    this->headerH = nullptr;
    this->headerV = nullptr;
}

bool sparse_Matrix::isEmpy() const {
    return this->headerH == nullptr && this->headerV == nullptr;
}

// ? Metodo para obtener una cabezera horizontal nodo en la matriz dispersa
nodeMatrix *sparse_Matrix::getHeaderH(int value) const {
    if (isEmpy()) return nullptr;

    nodeMatrix *aux = headerH;

    while (aux != nullptr) {
        if (aux->value == value) {
            return aux;
        }
        aux = aux->next;
    }

    return nullptr;
}

// ? Metodo para obtener una cabezera vertical nodo en la matriz dispersa
nodeMatrix *sparse_Matrix::getHeaderV(const int value) const {
    if (isEmpy()) return nullptr;

    nodeMatrix *aux = headerV;

    while (aux != nullptr) {
        if (aux->value == value) {
            return aux;
        }
        aux = aux->down;
    }

    return nullptr;
}

// ? Metodos para insertar cabezeras horizontale en la matriz dispersa
nodeMatrix *sparse_Matrix::insertHeaderH(int value) {
    nodeMatrix *newNode = new nodeMatrix(value);

    // ! Si la matriz esta vacia
    if (this->headerH == nullptr) {
        this->headerH = newNode;
        return newNode;
    }
    nodeMatrix *aux = headerH;

    while (aux->next != nullptr) {
        aux = aux->next;
    }

    aux->next = newNode;
    newNode->prev = aux;

    return newNode;
}

// ? Metodos para insertar cabezeras verticales en la matriz dispersa
nodeMatrix *sparse_Matrix::insertHeaderV(const int value) {
    nodeMatrix *newNode = new nodeMatrix(value);

    // ! Si la matriz esta vacia
    if (this->headerV == nullptr) {
        this->headerV = newNode;
        return newNode;
    }

    nodeMatrix *aux = headerV;

    while (aux->down != nullptr) {
        aux = aux->down;
    }

    aux->down = newNode;
    newNode->up = aux;

    return newNode;
}

// ? Metodo para iniciar  cabezeras en la matriz dispersa
void sparse_Matrix::insertHeaders(int value, int headerH, int headerV) {
    nodeMatrix *headH = nullptr;
    nodeMatrix *headV = nullptr;

    nodeMatrix *newUser = new nodeMatrix(value);

    if (isEmpy()) {
        headH = insertHeaderH(headerH);
        headV = insertHeaderV(headerV);
        insertFinal(newUser, headH, headV);
        return;
    }

    headH = getHeaderH(headerH);
    headV = getHeaderV(headerV);

    if (headH == nullptr && headV == nullptr) {
        headH = insertHeaderH(headerH);
        headV = insertHeaderV(headerV);
        insertFinal(newUser, headH, headV);
        return;
    }

    if (headH == nullptr) {
        headH = insertHeaderH(headerH);
        insertFinalH(newUser, headH);
        return;
    }

    if (headV == nullptr) {
        headV = insertHeaderV(headerV);
        insertFinalV(newUser, headV);
        return;
    }

    // ! Si ya existe la cabezera horizontal y vertical
    nodeMatrix *auxH = headH->down;
    nodeMatrix *userHeadV = nullptr;
    bool down = false;

    while (auxH != nullptr) {
        userHeadV = findHeaderV(auxH);
        down = moreDown(userHeadV, headerV);

        if (!down) break;

        auxH = auxH->down;
    }

    if (down) {
        insertFinalH(newUser, headH);
    } else {
        insertMiddleH(newUser, auxH);
    }

    nodeMatrix *auxV = headV->next;
    nodeMatrix *userHeadH = nullptr;
    bool right = false;

    while (auxV != nullptr) {
        userHeadH = findHeaderH(auxV);
        right = moreRight(userHeadH, headerH);

        if (!right) break;

        auxV = auxV->next;
    }

    if (right) {
        insertFinalV(newUser, headV);
    } else {
        insertMiddleV(newUser, auxV);
    }
}

void sparse_Matrix::insertFinal(nodeMatrix *value, nodeMatrix *headerH, nodeMatrix *headerV) {
    insertFinalH(value, headerH);
    insertFinalV(value, headerV);
}

void sparse_Matrix::insertFinalH(nodeMatrix *value, nodeMatrix *headerH) {
    nodeMatrix *aux = headerH;
    while (aux->down != nullptr) {
        aux = aux->down;
    }

    aux->down = value;
    value->up = aux;
}

void sparse_Matrix::insertFinalV(nodeMatrix *value, nodeMatrix *headerV) {
    nodeMatrix *aux = headerV;
    while (aux->next != nullptr) {
        aux = aux->next;
    }
    aux->next = value;
    value->prev = aux;
}

void sparse_Matrix::insertMiddleV(nodeMatrix *value, nodeMatrix *headerVN) {
    headerVN->prev->next = value;
    value->next = headerVN;
    value->prev = headerVN->prev;
    headerVN->prev = value;
}

void sparse_Matrix::insertMiddleH(nodeMatrix *value, nodeMatrix *headerHN) {
    headerHN->up->down = value;
    value->down = headerHN;
    value->up = headerHN->up;
    headerHN->up = value;
}

nodeMatrix *sparse_Matrix::findHeaderH(nodeMatrix *nodeH) const {
    nodeMatrix *aux = nodeH;
    while (aux->up != nullptr) {
        aux = aux->up;
    }
    return aux;
}

nodeMatrix *sparse_Matrix::findHeaderV(nodeMatrix *nodeV) const {
    nodeMatrix *aux = nodeV;
    while (aux->prev != nullptr) {
        aux = aux->prev;
    }
    return aux;
}

bool sparse_Matrix::moreDown(nodeMatrix *headerV, int headderValue) const {
    nodeMatrix *aux = headerV;
    while (aux != nullptr) {
        if (aux->value == headderValue) return true;
        aux = aux->down;
    }
    return false;
}

bool sparse_Matrix::moreRight(nodeMatrix *headerH, int headderValue) const {
    nodeMatrix *aux = headerH;
    while (aux != nullptr) {
        if (aux->value == headderValue) return true;
        aux = aux->next;
    }
    return false;
}
