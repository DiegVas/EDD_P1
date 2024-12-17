#include <iostream>
#include <string>
#include "./content/admin/admin.h"
#include "content/userMenu/userMenu.h"
#include "controllers/dataStructure/circularLinked/circularLinked.h"
//Carne 202300638
// Diego Alejandro Vásquez Alonzo

void show_Menu();

void login(sparse_Matrix *userMatrix, linkedList *activeList, CircularLinkedList *circularList);

// TODO : Credenciales de usuario admin
const std::string ADMIN_USER = "admin";
const std::string ADMIN_PASS = "admin";



int main()
{
    int choice;
    linkedList activeList = linkedList();
    sparse_Matrix sparseMatrix = sparse_Matrix();
    CircularLinkedList circularList = CircularLinkedList();

    // ! Usuarios y activos quemados
   // userStruct userTest = userStruct("elian_estrada", "Usuario completo", "", "", "");
    userStruct users[] = {
        {"elian_estrada", "Elian Estrada", "1234", "igss", "guatemala"},
        {"juanito", "Juan Perez", "4567", "max", "jutiapa"},
        {"pedrito", "Pedro Rodriguez", "48956", "usac", "jalapa"},
        {"mafer", "Maria Fernanda", "54312", "cinepolis", "peten"},
        {"juanma", "Juan Manuel", "32897", "usac", "guatemala"},
        {"casimiro", "Carlos Perez", "721896", "max", "guatemala"},
        {"fuego03", "Fernando Mendez", "891346", "cinepolis", "jutiapa"},
        {"azurdia", "Alejandra Guzman", "780145", "usac", "jutiapa"},
        {"incrediboy", "Iraldo Martinez", "201598", "max", "jutiapa"},
        {"alcachofa", "Antonio Lopez", "20435", "usac", "jalapa"}
    };

    for (auto &user : users) {
        sparseMatrix.insertHeaders(user);
    }

    // ! Activos quemados
    //activeStruct activeTest = activeStruct("Activo 1", "Activo de prueba", userTest.userName);


    //userTest.actives->insert(&activeTest, &activeList);


     do {
         show_Menu();
         std::cin >> choice;
         std::cout << std::endl;

         switch (choice) {
             case 1:
                 login(&sparseMatrix, &activeList, &circularList);
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

void login(sparse_Matrix *userMatrix, linkedList *activeList, CircularLinkedList *circularList)
{
    std::cout << "*-------------------* LOGIN *-------------------*" << std::endl;
    std::string username, password, country, company;
    std::cout << "Ingrese su usuario: ";
    std::cin >> username;
    std::cout << "Ingrese la contraseña: ";
    std::cin >> password;

    if (username == ADMIN_USER && password == ADMIN_PASS) menu_Admin(userMatrix, circularList);

    std::cout << "Ingrese su pais: ";
    std::cin >> country;
    std::cout << "Ingrese su empresa: ";
    std::cin >> company;
    std::cout << std::endl;

    userStruct userLogin = userStruct(username, "",password, company, country);
    nodeMatrix *aux = userMatrix->searchNode(userLogin);

    if (aux != nullptr && aux->user->password == password) {
        std::cout << "Bienvenido " << aux->userName << std::endl;
        userMenu(aux, activeList, circularList);
    } else {
        std::cout << "Usuario no encontrado" << std::endl;
    }

}


