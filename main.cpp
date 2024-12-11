#include <iostream>
#include <string>
#include "./content/admin/admin.h"
#include "controllers/sparseMatrix.h"

void show_Menu();

void login();

// TODO : Credenciales de usuario admin
const std::string ADMIN_USER = "admin";
const std::string ADMIN_PASS = "admin";

int main() {
    sparse_Matrix *matrix = new sparse_Matrix();
    matrix->insertHeaders("Usuario11", "Guate", "Max");
    matrix->insertHeaders("Usuario22", "Villa", "Cine");
    matrix->insertHeaders("Usuario12", "Guate", "CIne");
    matrix->insertHeaders("Usuario21", "guate", "Maxi");


    //
    // int choice;
    //
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

void show_Menu() {
    std::cout << "//////////////// RENTA DE ACTIVOS ////////////////" << std::endl;
    std::cout << "[1]. Login" << std::endl;
    std::cout << "[2]. Exit" << std::endl;
    std::cout << "Ingrese una opcion:  ";
}

void login() {
    std::cout << "*-------------------* LOGIN *-------------------*" << std::endl;
    std::string username, password;
    std::cout << "Ingrese su usuario: ";
    std::cin >> username;
    std::cout << "Ingrese la contraseña: ";
    std::cin >> password;

    if (username == ADMIN_USER && password == ADMIN_PASS) {
        std::cout << "Bienvenido " << username << "!" << std::endl;
        menu_Admin();
    }
}


