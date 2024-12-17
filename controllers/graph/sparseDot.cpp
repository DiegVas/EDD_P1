#include <string>
#include <sstream>
#include "../dataStructure/sparseMatrix/sparseMatrix.h"

std::string sparseDot(sparse_Matrix* matrix) {
    std::stringstream dotContent;
    dotContent << "digraph G {\n";
    dotContent << "label=\"Reporte de matriz dispersa\"";
    dotContent << "labelloc=\"t\"";
    dotContent << "    node [shape=box width=1.2 style=filled fillcolor=\"#85A98F\" color=transparent ];\n";
    dotContent << "A0 [label=\"admin\" group=0 ]\n";
    dotContent << "A0 -> " << matrix->headerH->userName << ";\n";
    dotContent << "A0 -> " << matrix->headerV->userName << ";\n";

    // ! Primero las cabeceras horizontales
    dotContent<<"/*------------------- Cabeceras horizontales -------------------*/\n";
    nodeMatrix *auxH = matrix->headerH;
    int group = 1;
    while (auxH!=nullptr)
    {
        dotContent << auxH->userName << " [label=\"" << auxH->userName << "\" group=" << group << " ];\n";
        auxH = auxH->next;
        group++;
    }

    // ! Luego las cabeceras verticales
    dotContent<<"/*------------------- Cabeceras verticales -------------------*/\n";

    nodeMatrix *auxV = matrix->headerV;
    while (auxV!=nullptr)
    {
        dotContent << auxV->userName << " [label=\"" << auxV->userName << "\" group=0 ];\n";
        auxV = auxV->down;
    }

    // ! Columnas

    dotContent<<"/*------------------- Columnas -------------------*/\n";
    auxH = matrix->headerH;
    auxV = nullptr;
    group = 1;
    while (auxH!=nullptr)
    {
        auxV = auxH->down;
        while (auxV!=nullptr)
        {
            dotContent << auxV->user->cell << " [label=\"" << auxV->userName << "\" group=" << group <<" ];\n";
            auxV = auxV->down;
        }
        group++;
        auxH = auxH->next;
    }

    dotContent<<"/*------------------- Enlaces horizontales -------------------*/\n";

    auxH = matrix->headerH;
    while (auxH != nullptr)
    {
        if (auxH->next != nullptr)
        {
            dotContent << auxH->userName << " -> " << auxH->next->userName << ";\n";
        }
        else
        {
            // ! Enlaces inversos
            while (auxH->prev != nullptr)
            {
                dotContent << auxH->userName << " -> " << auxH->prev->userName << ";\n";
                auxH = auxH->prev;
            }
            break;
        };
        auxH = auxH->next;
    }

    // ! Horizontales de nodos
    auxH = nullptr;
    auxV = matrix->headerV;

    while (auxV != nullptr)
    {
        auxH = auxV->next;
        dotContent << auxV->userName << " -> " << auxH->user->cell << ";\n";
        while (auxH != nullptr)
        {
            if (auxH->next != nullptr)
            {
                dotContent << auxH->user->cell << " -> " << auxH->next->user->cell << ";\n";
            }
            else
            {
                // ! Enlaces inversos
                while (auxH->prev != nullptr)
                {
                    auxH->prev->user != nullptr ? dotContent << auxH->user->cell << " -> " << auxH->prev->user->cell << ";\n" : dotContent << auxH->user->cell << " -> " << auxH->prev->userName << ";\n";
                    auxH = auxH->prev;
                }
                break;
            }
            auxH = auxH->next;
        }
        auxV = auxV->down;
    }

    dotContent << "/*------------------- Enlaces verticales -------------------*/\n";
    auxV = matrix->headerV;
    while (auxV != nullptr)
    {
        if (auxV->down != nullptr)
        {
            dotContent << auxV->userName << " -> " << auxV->down->userName << ";\n";
        }
        else
        {
            // ! Enlaces inversos
            while (auxV->up != nullptr)
            {
                dotContent << auxV->userName << " -> " << auxV->up->userName << ";\n";
                auxV = auxV->up;
            }
            break;
        }
        auxV = auxV->down;
    }

    // ! Verticales de nodos
    auxH = matrix->headerH;
    auxV = nullptr;
    while (auxH != nullptr)
    {
        auxV = auxH->down;
        dotContent << auxH->userName << " -> " << auxV->user->cell << ";\n";
        while (auxV != nullptr)
        {
            if (auxV->down != nullptr)
            {
                dotContent << auxV->user->cell << " -> " << auxV->down->user->cell << ";\n";
            }
            else
            {
                // ! Enlaces inversos
                while (auxV->up != nullptr)
                {
                    auxV->up->user != nullptr ? dotContent << auxV->user->cell << " -> " << auxV->up->user->cell << ";\n" : dotContent << auxV->user->cell << " -> " << auxV->up->userName << ";\n";
                    auxV = auxV->up;
                }
                break;
            }
            auxV = auxV->down;
        }
        auxH = auxH->next;
    }

    dotContent << "/*------------------- Encuadre -------------------*/\n";

    auxH = matrix->headerH;
    dotContent << "{ rank=same; A0;";
    while (auxH!=nullptr)
    {
        dotContent << auxH->userName << ";";
        auxH = auxH->next;
    }
    dotContent << "}\n";

    auxH = nullptr;
    auxV = matrix->headerV;
    while (auxV!=nullptr)
    {
        auxH = auxV->next;
        dotContent << "{ rank=same; " << auxV->userName << ";";
        while (auxH!=nullptr)
        {
            dotContent << auxH->user->cell << ";";
            auxH = auxH->next;
        }
        dotContent << "}\n";
        auxV = auxV->down;
        auxH = matrix->headerH;
    }

    dotContent << "}\n";
    return dotContent.str();
}


