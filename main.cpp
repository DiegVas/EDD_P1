#include <iostream>
#include <string>
#include "./content/admin/admin.h"
#include "controllers/dataStructure/sparseMatrix/sparseMatrix.h"
#include "controllers/graph/graphGenerator.h"
#include "controllers/graph/sparseDot.h"


void show_Menu();

void login(sparse_Matrix *userMatrix);


// TODO : Credenciales de usuario admin
const std::string ADMIN_USER = "admin";
const std::string ADMIN_PASS = "admin";

int main()
{
    int choice;
    sparse_Matrix sparseMatrix = sparse_Matrix();

    // Crear usuarios que representan las casillas (columna, fila)
    userStruct user11 = userStruct("user11", "User 11", "123" , "Empresa1","Guatemala"); // Columna 1, Fila 1
    userStruct user12 = userStruct("user12", "User 12", "123", "Empresa2","Guatemala"); // Columna 1, Fila 2
    userStruct user21 = userStruct("user21", "User 21", "123", "Empresa1","Mexico");    // Columna 2, Fila 1
    userStruct user22 = userStruct("user22", "User 22", "123",  "Empresa2","Mexico");    // Columna 2, Fila 2
    userStruct user31 = userStruct("user31", "User 31", "123",  "Empresa1","El Salvador"); // Columna 3, Fila 1
    userStruct user32 = userStruct("user32", "User 32", "123",  "Empresa2","El Salvador"); // Columna 3, Fila 2

    // Insertar los nodos en la matriz
    sparseMatrix.insertHeaders(user11); // Guatemala, Empresa1
    sparseMatrix.insertHeaders(user12); // Guatemala, Empresa2
    sparseMatrix.insertHeaders(user21); // Mexico, Empresa1
    sparseMatrix.insertHeaders(user22); // Mexico, Empresa2
    sparseMatrix.insertHeaders(user31); // El Salvador, Empresa1
    sparseMatrix.insertHeaders(user32); // El Salvador, Empresa2



    generateGraphvizFiles(sparseDot(&sparseMatrix), "sparseMatrix");

    // do {
    //     show_Menu();
    //     std::cin >> choice;
    //     std::cout << std::endl;
    //
    //     switch (choice) {
    //         case 1:
    //             login(&sparseMatrix);
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


