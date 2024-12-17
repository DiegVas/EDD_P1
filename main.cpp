#include <iostream>
#include <string>
#include "./content/admin/admin.h"
#include "content/userMenu/userMenu.h"

void show_Menu();

void login(sparse_Matrix *userMatrix, linkedList *activeList);


// TODO : Credenciales de usuario admin
const std::string ADMIN_USER = "admin";
const std::string ADMIN_PASS = "admin";

int main()
{
    int choice;
    linkedList activeList = linkedList();
    sparse_Matrix sparseMatrix = sparse_Matrix();

    // ! Usuarios y activos quemados
    userStruct userTest = userStruct("test", "Usuario completo", "123", "max", "gua");
    userStruct userTest1 = userStruct("test1", "Usuario completo 1", "123", "max", "gua");
    userStruct userTest2 = userStruct("test2", "Usuario completo 2", "123", "max", "distelsa");

    // ! Activos quemados
    activeStruct activeTest = activeStruct("Activo 1", "Activo de prueba", userTest.userName);
    activeStruct actoveTest1 = activeStruct("activo2", "activo prueba", userTest1.userName);
    activeStruct activeTest2 = activeStruct("activo3", "activo prueba", userTest2.userName);

    userTest.actives->insert(&activeTest, &activeList);
    userTest1.actives->insert(&actoveTest1, &activeList);
    userTest2.actives->insert(&activeTest2, &activeList);
    sparseMatrix.insertHeaders(userTest);
    sparseMatrix.insertHeaders(userTest1);
    sparseMatrix.insertHeaders(userTest2);

     do {
         show_Menu();
         std::cin >> choice;
         std::cout << std::endl;

         switch (choice) {
             case 1:
                 login(&sparseMatrix, &activeList);
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

void login(sparse_Matrix *userMatrix, linkedList *activeList)
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

    userStruct userLogin = userStruct(username, "",password, company, country);
    nodeMatrix *aux = userMatrix->searchNode(userLogin);

    if (aux != nullptr && aux->user->password == password) {
        std::cout << "Bienvenido " << aux->userName << std::endl;
        userMenu(aux, activeList);
    } else {
        std::cout << "Usuario no encontrado" << std::endl;
    }

}


