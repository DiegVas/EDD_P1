#include <iostream>
#include <string>
#include "./content/admin/admin.h"
#include "controllers/dataStructure/sparseMatrix/sparseMatrix.h"
#include "controllers/dataStructure/avlTree/avlTree.h"

void show_Menu();

void login();

// TODO : Credenciales de usuario admin
const std::string ADMIN_USER = "admin";
const std::string ADMIN_PASS = "admin";

int main()
{
    sparse_Matrix* matrix = new sparse_Matrix();
    avlTree* tree = new avlTree();

    tree->insert(0);
    tree->insert(1);
    tree->insert(2);
    tree->insert(3);
    tree->insert(4);
    tree->insert(5);
    tree->insert(6);
    tree->insert(7);
    tree->insert(8);
    tree->insert(9);
    tree->insert(10);


    int choice;

    // do {
    //     show_Menu();
    //     std::cin >> choice;
    //
    //     switch (choice) {
    //         case 1:
    //             login();
    //             break;
    //         case 2:
    //             std::cout << "Gracias por preferirnos!." << std::endl;
    //             break;
    //         default:
    //             std::cout << "Por favor ingrese una opcion valida" << std::endl;
    //     }
    //
    // } while (choice != 2);
}

void show_Menu()
{
    std::cout << "//////////////// RENTA DE ACTIVOS ////////////////" << std::endl;
    std::cout << "[1]. Login" << std::endl;
    std::cout << "[2]. Exit" << std::endl;
    std::cout << "Ingrese una opcion:  ";
}

void login()
{
    std::cout << "*-------------------* LOGIN *-------------------*" << std::endl;
    std::string username, password;
    std::cout << "Ingrese su usuario: ";
    std::cin >> username;
    std::cout << "Ingrese la contraseña: ";
    std::cin >> password;

    if (username == ADMIN_USER && password == ADMIN_PASS)
    {
        std::cout << "Bienvenido " << username << "!" << std::endl;
        menu_Admin();
    }
}


