#include <string>
#include <sstream>
#include "../dataStructure/sparseMatrix/sparseMatrix.h"

std::string sparseDot(sparse_Matrix* matrix) {
    std::stringstream dotContent;
    dotContent << "digraph G {\n";
    dotContent << "    node [shape=rectangle];\n";
    dotContent << "A0 [label=\"admin\"]\n";

    // ! Primero las cabeceras horizontales
    dotContent<<"/*------------------- Cabeceras horizontales -------------------*/\n";
    int row=0;
    nodeMatrix *auxH = matrix->headerH;
    while (auxH!=nullptr)
    {
        dotContent << "H" << row << " [label=\"" << auxH->userName << "\"];\n";
        row++;
        auxH = auxH->next;
    }

    // ! Luego las cabeceras verticales
    dotContent<<"/*------------------- Cabeceras verticales -------------------*/\n";
    int column=0;
    nodeMatrix *auxV = matrix->headerV;
    while (auxV!=nullptr)
    {
        dotContent << "V" << column << " [label=\"" << auxV->userName << "\"];\n";
        column++;
        auxV = auxV->down;
    }

    // ! Columnas
    dotContent<<"/*------------------- Columnas -------------------*/\n";
    auxV = matrix->headerV;
    auxH = matrix->headerH;
    nodeMatrix *aux = auxH;
    int colCounter = 1;
    int rowCounter = 1;

    while (auxH!=nullptr)
    {
        aux = auxH;
        aux = aux->down;
        auxV = matrix->headerV;
        colCounter = 1;
        while (auxV!=nullptr)
        {
            if (matrix->findHeaderV(aux)->userName == auxV->userName)
            {
                dotContent << "H" << rowCounter << "V" << colCounter << " [label=\"" << aux->userName << "\"];\n";
                aux = aux->down;
            }
            colCounter++;
            auxV = auxV->down;
        }

        rowCounter++;
        auxH = auxH->next;
    }


    // ! Relaciones Cabezales horizontales
    dotContent<<"/*------------------- Relaciones horizontales -------------------*/\n";
    colCounter = 1;
    nodeMatrix *aux3 = matrix->headerH;
    dotContent << "A0 -> H0";
    while (aux3->next!=nullptr)
    {
        dotContent << " H"<<colCounter-1 <<" -> H" << colCounter;
        colCounter++;
        aux3 = aux3->next;
    }
    colCounter--;
    dotContent << ";\n";
    // ! Relaciones Cabezales horizontales inversas
    while (aux3->prev!=nullptr)
    {
        dotContent << " H"<<colCounter <<" -> H" << colCounter-1;
        colCounter--;
        aux3 = aux3->prev;
    }
    dotContent << " H0 -> A0;\n";

    // ! Relaciones horizontales de los hijos
    colCounter = 1;
    rowCounter = 1;
    auxH = matrix->headerH;
    auxV = matrix->headerV;
    aux = auxV;

    while (auxV != nullptr)
    {
        aux = auxV;
        aux = auxV->next;
        auxH = matrix->headerH;
         while (auxH != nullptr)
        {
            if (matrix->findHeaderH(aux)->userName == auxH->userName)
            {
                dotContent << "H" << rowCounter << "V" << colCounter << " -> H" << rowCounter << ";\n";
                dotContent << "H" << rowCounter << "V" << colCounter << " -> V" << colCounter << ";\n";
                aux = aux->next;

            }
             rowCounter++;
            auxH = auxH->next;
        }


        colCounter++;
        auxV->down;
    }


    dotContent << "}\n";
    return dotContent.str();
}


