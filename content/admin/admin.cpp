#include <iostream>

#include "../../controllers/dataStructure/sparseMatrix/sparseMatrix.h"

void show_MenuAdmin();
void registerUser(sparse_Matrix *userMatrix);

// ? Funciones de admin
void menu_Admin(sparse_Matrix *userMatrix) {
    int choiceAdmin;

    do {
        show_MenuAdmin();
        std::cin >> choiceAdmin;
        std::cout << std::endl;

        switch (choiceAdmin) {
            case 1:
                std::cout << "*-------------------* Registrar Usuario *-------------------*" << std::endl;
                registerUser(userMatrix);
                choiceAdmin = 0;
                break;
            case 2:
                std::cout << "*-------------------* Reporte matriz dispersa *-------------------*" << std::endl;
                break;
            case 3:
                std::cout << "*-------------------* Reporte activos disponibles de un departamento *-------------------*" << std::endl;
                break;
            case 4:
                std::cout << "*-------------------* Reporte activos disponibles de una empresa *-------------------*" << std::endl;
                break;
            case 5:
                std::cout << "*-------------------* Reporte transacciones *-------------------*" << std::endl;
                break;
            case 6:
                std::cout << "*-------------------* Reporte activos de un usuario *-------------------*" << std::endl;
                break;
            case 7:
                std::cout << "*-------------------* Reporte rentados por un usuario *-------------------*" << std::endl;
                break;
            case 8:
                std::cout << "*-------------------* Ordenar transacciones *-------------------*" << std::endl;
                break;
            case 9:
                std::cout << "Saliendo..." << std::endl;
                std::cout << std::endl;
                break;
            default:
                std::cout << "Por favor ingrese una opcion valida" << std::endl;
                break;
        }

    } while (choiceAdmin != 9);
}

void show_MenuAdmin() {
    std::cout << "//////////////// ADMIN MENU ////////////////" << std::endl;
    std::cout << "[1]. Registrar Usuario" << std::endl;
    std::cout << "[2]. Reporte matriz dispersa" << std::endl;
    std::cout << "[3]. Reporte activos disponibles de un departamento" << std::endl;
    std::cout << "[4]. Reporte activos disponibles de una empresa" << std::endl;
    std::cout << "[5]. Reporte transacciones" << std::endl;
    std::cout << "[6]. Reporte activos de un usuario" << std::endl;
    std::cout << "[7]. Reporte rentados por un usuario" << std::endl;
    std::cout << "[8]. Ordenar transacciones" << std::endl;
    std::cout << "[9]. Salir" << std::endl;
    std::cout << "Ingrese una opcion:  ";
}

void registerUser(sparse_Matrix *userMatrix)
{
    std::string fullName, password, userName, company, country;
    int error = 0;
    std::cout << "...Ingrese el nombre completo del usuario...: ";
    std::cin >> fullName;
    std::cout << "...Ingrese la contraseña del usuario...: ";
    std::cin >> password;
    std::cout << "...Ingrese el userName del usuario...: ";
    std::cin >> userName;
    std::cout << "...Ingrese la empresa del usuario...: ";
    std::cin >> company;
    std::cout << "...Ingrese el pais del usuario...: ";
    std::cin >> country;
    std::cout << std::endl;

    userStruct *newUser = new userStruct(userName, fullName, password, company, country);
    error = userMatrix->insertHeaders(  *newUser);
    if (error == 0)
    {
        std::cout << "||||| Usuario registrado exitosamente! |||||" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "¡¡¡¡ El usuario ya existe !!!!" << std::endl;
        std::cout << std::endl;
    }
}