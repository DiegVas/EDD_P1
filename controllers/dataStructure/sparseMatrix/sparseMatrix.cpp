

#include <iostream>
#include "../../nodes/disperseMatrix/nodeMatrix.h"
#include "sparseMatrix.h"

sparse_Matrix::sparse_Matrix()
{
    this->headerH = nullptr;
    this->headerV = nullptr;
}

bool sparse_Matrix::isEmpy() const
{
    return this->headerH == nullptr && this->headerV == nullptr;
}

nodeMatrix* sparse_Matrix::getHeaderH(std::string value) const
{
    if (isEmpy()) return nullptr;

    nodeMatrix* aux = headerH;

    while (aux != nullptr)
    {
        if (aux->userName == value) return aux;
        aux = aux->next;
    }

    return nullptr;
}

nodeMatrix* sparse_Matrix::getHeaderV(std::string value) const
{
    if (isEmpy()) return nullptr;

    nodeMatrix* aux = headerV;

    while (aux != nullptr)
    {
        if (aux->userName == value) return aux;

        aux = aux->down;
    }

    return nullptr;
}

nodeMatrix* sparse_Matrix::insertHeaderH(std::string value)
{
    nodeMatrix* newNode = new nodeMatrix(value);

    // ! Si la matriz esta vacia
    if (this->headerH == nullptr)
    {
        this->headerH = newNode;
        return newNode;
    }

    nodeMatrix* aux = headerH;

    while (aux->next != nullptr) aux = aux->next;

    aux->next = newNode;
    newNode->prev = aux;

    return newNode;
}

nodeMatrix* sparse_Matrix::insertHeaderV(std::string value)
{
    nodeMatrix* newNode = new nodeMatrix(value);

    // ! Si la matriz esta vacia
    if (this->headerV == nullptr)
    {
        this->headerV = newNode;
        return newNode;
    }

    nodeMatrix* aux = headerV;

    while (aux->down != nullptr) aux = aux->down;

    aux->down = newNode;
    newNode->up = aux;

    return newNode;
}

int sparse_Matrix::insertHeaders(userStruct &user)
{
    std::string company = user.company;
    std::string country = user.country;

    nodeMatrix* headH = nullptr;
    nodeMatrix* headV = nullptr;

    nodeMatrix* newUser = new nodeMatrix(&user);
    newUser->user = &user;

    if (isEmpy())
    {
        headH = insertHeaderH(country);
        headV = insertHeaderV(company);
        insertFinal(newUser, headH, headV);
        return 0;
    }

    headH = getHeaderH(country);
    headV = getHeaderV(company);

    if (headH == nullptr && headV == nullptr)
    {
        headH = insertHeaderH(country);
        headV = insertHeaderV(company);
        insertFinal(newUser, headH, headV);
        return 0;
    }
    else if (headH == nullptr)
    {
        headH = insertHeaderH(country);
        insertFinal(newUser, headH, headV);
        return 0;
    }
    else if (headV == nullptr)
    {
        headV = insertHeaderV(company);
        insertFinal(newUser, headH, headV);
        return 0;
    }

    nodeMatrix* ThereisNodo = isOccupied(headH, headV);
    if (ThereisNodo != nullptr) return insertBehind(newUser, ThereisNodo);


    // ! Si ya existe la cabezera horizontal y vertical
    nodeMatrix* auxH = headH->down;
    nodeMatrix* userHeadV = nullptr;
    bool down = false;

    while (auxH != nullptr)
    {
        userHeadV = findHeaderV(auxH);
        down = moreDown(userHeadV, company);

        if (!down) break;
        auxH = auxH->down;
    }

    down ? insertFinalH(newUser, headH) : insertMiddleH(newUser, auxH);

    nodeMatrix* auxV = headV->next;
    nodeMatrix* userHeadH = nullptr;
    bool right = false;

    while (auxV != nullptr)
    {
        userHeadH = findHeaderH(auxV);
        right = moreRight(userHeadH, country);

        if (!right) break;

        auxV = auxV->next;
    }

    right ? insertFinalV(newUser, headV) : insertMiddleV(newUser, auxV);
    return 0;
}

void sparse_Matrix::insertFinal(nodeMatrix* value, nodeMatrix* headerH, nodeMatrix* headerV)
{
    insertFinalH(value, headerH);
    insertFinalV(value, headerV);
}

void sparse_Matrix::insertFinalH(nodeMatrix* value, nodeMatrix* headerH)
{
    nodeMatrix* aux = headerH;
    while (aux->down != nullptr) aux = aux->down;

    aux->down = value;
    value->up = aux;
}

void sparse_Matrix::insertFinalV(nodeMatrix* value, nodeMatrix* headerV)
{
    nodeMatrix* aux = headerV;
    while (aux->next != nullptr) aux = aux->next;

    aux->next = value;
    value->prev = aux;
}

void sparse_Matrix::insertMiddleV(nodeMatrix* value, nodeMatrix* headerVN)
{
    headerVN->prev->next = value;
    value->next = headerVN;
    value->prev = headerVN->prev;
    headerVN->prev = value;
}

void sparse_Matrix::insertMiddleH(nodeMatrix* value, nodeMatrix* headerHN)
{
    headerHN->up->down = value;
    value->down = headerHN;
    value->up = headerHN->up;
    headerHN->up = value;
}

nodeMatrix* sparse_Matrix::findHeaderH(nodeMatrix* nodeH)
{
    nodeMatrix* aux = nodeH;
    while (aux->up != nullptr) aux = aux->up;
    return aux;
}

nodeMatrix* sparse_Matrix::findHeaderV(nodeMatrix* nodeV)
{
    nodeMatrix* aux = nodeV;
    while (aux->prev != nullptr)
    {
        aux = aux->prev;
    }
    return aux;
}

bool sparse_Matrix::moreDown(nodeMatrix* headerV, const std::string& headderValue)
{
    nodeMatrix* aux = headerV;
    while (aux != nullptr)
    {
        if (aux->userName == headderValue) return true;
        aux = aux->down;
    }
    return false;
}

bool sparse_Matrix::moreRight(nodeMatrix* headerH, const std::string& headderValue)
{
    nodeMatrix* aux = headerH;
    while (aux != nullptr)
    {
        if (aux->userName == headderValue) return true;
        aux = aux->next;
    }
    return false;
}

nodeMatrix* sparse_Matrix::isOccupied(nodeMatrix* headerH, nodeMatrix* headerV)
{
    nodeMatrix* auxH = headerH->down;
    nodeMatrix* headV = nullptr;
    nodeMatrix* find = nullptr;

    while (auxH != nullptr)
    {
        find = findHeaderV(auxH);
        if (find == headerV) return auxH;
        auxH = auxH->down;
    }

    return nullptr;
}

int sparse_Matrix::insertBehind(nodeMatrix* newNode, nodeMatrix* firstNode)
{
    nodeMatrix* aux = firstNode;

    // ! Si solo existe un nodo
    if (aux->behind == nullptr && aux->userName == newNode->userName) return 1;

    while (aux->behind != nullptr)
    {
        if (aux->userName == newNode->userName) return 1;
        aux = aux->behind;
    }
    newNode->front = aux;
    aux->behind = newNode;
    return 0;
}

nodeMatrix* sparse_Matrix::searchNode(const userStruct& user){
    nodeMatrix* auxH = headerH;
    nodeMatrix* auxV = headerV;
    auxH = getHeaderH(user.country);
    if (auxH == nullptr) return nullptr;
    auxV = getHeaderV(user.company);
    if (auxV == nullptr) return nullptr;


    while (auxH != nullptr)
    {
        if (findHeaderV(auxH)->userName == auxV->userName)
        {
            while (auxH != nullptr)
            {
                if (auxH->userName == user.userName) return auxH;
                auxH = auxH->behind;
            }
            return nullptr;
        }
        auxH = auxH->down;
    }

    return nullptr;
}
