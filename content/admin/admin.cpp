#include <iostream>

void show_MenuAdmin();

// ? Funciones de admin
void menu_Admin() {
    int choiceAdmin;

    do {
        show_MenuAdmin();
        std::cin >> choiceAdmin;

        switch (choiceAdmin) {
            case 1:
                std::cout << "*-------------------* Registrar Usuario *-------------------*" << std::endl;
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
