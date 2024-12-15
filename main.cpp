#include <iostream>
#include <string>
#include "./content/admin/admin.h"
#include "controllers/dataStructure/sparseMatrix/sparseMatrix.h"
#include "controllers/dataStructure/avlTree/avlTree.h"
#include "controllers/structs/activeStruct.h"


void show_Menu();

void login(sparse_Matrix *userMatrix);

// TODO : Credenciales de usuario admin
const std::string ADMIN_USER = "admin";
const std::string ADMIN_PASS = "admin";

int main()
{
    int choice;
    sparse_Matrix sparseMatrix = sparse_Matrix();

    userStruct userTest1 = userStruct("user1", "User 1", "123", "Guatemala", "Empresa1");
    userStruct userTest2 = userStruct("user2", "User 2", "123", "Guatemala", "Empresa2");

    sparseMatrix.insertHeaders(userTest1);
    sparseMatrix.insertHeaders(userTest2);

    do {
        show_Menu();
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1:
                login(&sparseMatrix);
                break;
            case 2:
                std::cout << "Gracias por preferirnos!." << std::endl;
                break;
            default:
                std::cout << "Por favor ingrese una opcion valida" << std::endl;
        }

    } while (choice != 2);
}

void show_Menu()
{
    std::cout << "//////////////// RENTA DE ACTIVOS ////////////////" << std::endl;
    std::cout << "*-------------------* MENU *-------------------*" << std::endl;
    std::cout << "[1]. Login" << std::endl;
    std::cout << "[2]. Exit" << std::endl;
    std::cout << "Ingrese una opcion:  ";

}

void login(sparse_Matrix *userMatrix)
{
    std::cout << "*-------------------* LOGIN *-------------------*" << std::endl;
    std::string username, password, country, company;
    std::cout << "Ingrese su usuario: ";
    std::cin >> username;
    std::cout << "Ingrese la contraseña: ";
    std::cin >> password;

    if (username == ADMIN_USER && password == ADMIN_PASS) menu_Admin(userMatrix);

    std::cout << "Ingrese su pais: ";
    std::cin >> country;
    std::cout << "Ingrese su empresa: ";
    std::cin >> company;
    std::cout << std::endl;

    userStruct userLogin = userStruct(username, "",password, country, company);
    nodeMatrix *aux = userMatrix->searchNode(userLogin);
    if (aux != nullptr) {
        std::cout << "Bienvenido " << aux->userName << std::endl;
    } else {
        std::cout << "Usuario no encontrado" << std::endl;
    }

}


