#include <iostream>
#include "admin.h"
#include "../../controllers/graph/sparseDot.h"
#include "../../controllers/graph/avlDot.h"
#include "../../controllers/graph/graphGenerator.h"
#include "../../controllers/graph/linkedDot.h"

void show_MenuAdmin();
void registerUser(sparse_Matrix *userMatrix);

void reportActiveDepartment(sparse_Matrix *userMatrix)
{
    std::string departSearch;
    std::cout << "Ingrese el departamento a buscar: ";
    std::cin >> departSearch;

    nodeMatrix* department = userMatrix->getHeaderH(departSearch);

    if (department != nullptr) {
        std::string departmentReport;
        department = department->down;
        nodeMatrix* departmentBehin = nullptr;

        departmentReport += "digraph AVLTree {\n";
        departmentReport += "label=" + departSearch + ";\n";
        departmentReport += "labelloc = \"t\";\n";
        departmentReport += "fontsize = 15;\n";

        while (department != nullptr)
        {
            departmentBehin = department;
            while (departmentBehin != nullptr)
            {
                departmentReport += generateAVLSubGraphDot(departmentBehin->user->actives, departmentBehin->user->userName);
                departmentBehin = departmentBehin->behind;
            }
            department = department->down;
        }
        departmentReport += "}\n";
        generateGraphvizFiles(departmentReport, "Activos_Disponibles_Departamento" + departSearch);
    } else {
        std::cout << "Departamento no encontrado" << std::endl;
    }
};

void reportActiveCompany(sparse_Matrix *userMatrix)
{
    std::string companySearch;
    std::cout << "Ingrese la empresa a buscar: ";
    std::cin >> companySearch;

    nodeMatrix* company = userMatrix->getHeaderV(companySearch);

    if (company != nullptr) {
        std::string companyReport;
        company = company->next;
        nodeMatrix* companyBehin = nullptr;

        companyReport += "digraph AVLTree {\n";
        companyReport += "label=" + companySearch + ";\n";
        companyReport += "labelloc = \"t\";\n";
        companyReport += "fontsize = 15;\n";

        while (company != nullptr)
        {
            companyBehin = company;
            while (companyBehin != nullptr)
            {
                companyReport += generateAVLSubGraphDot(companyBehin->user->actives, companyBehin->user->userName);
                companyBehin = companyBehin->behind;
            }
            company = company->next;
        }
        companyReport += "}\n";
        generateGraphvizFiles(companyReport, "Activos_Disponibles_Empresa" + companySearch);
    } else {
        std::cout << "Empresa no encontrada" << std::endl;
    }
};

void reportActiveUser(sparse_Matrix *userMatrix)
{
    std::string userSearch, countrySearch, companySearch;
    std::cout << "Ingrese el pais a limitar: ";
    std::cin >> countrySearch;
    std::cout << "Ingrese la empresa a limitar: ";
    std::cin >> companySearch;
    std::cout << "Ingrese el usuario a buscar: ";
    std::cin >> userSearch;

    userStruct userSearchStruct = userStruct(userSearch, "", "", companySearch, countrySearch);

    nodeMatrix* user = userMatrix->searchNode(userSearchStruct);

    if (user != nullptr) {
        std::string userReport;
        userReport += generateAvlDot(user->user->actives, user->user->userName);
        generateGraphvizFiles(userReport, "Activos_Disponibles_Usuario" + userSearch);
    } else {
        std::cout << "Usuario no encontrado" << std::endl;
    }
};

void reportRentedUser(sparse_Matrix *userMatrix)
{
    std::string userSearch, countrySearch, companySearch;
    std::cout << "Ingrese el pais a limitar: ";
    std::cin >> countrySearch;
    std::cout << "Ingrese la empresa a limitar: ";
    std::cin >> companySearch;
    std::cout << "Ingrese el usuario a buscar: ";
    std::cin >> userSearch;

    userStruct userSearchStruct = userStruct(userSearch, "", "", companySearch, countrySearch);

    nodeMatrix* user = userMatrix->searchNode(userSearchStruct);

    if (user != nullptr) {
        std::string userReport;
        userReport += generateLinkedListDot(user->user->rentActives->head);
        generateGraphvizFiles(userReport, "Activos_Rentados_Usuario" + userSearch);
    } else {
        std::cout << "Usuario no encontrado" << std::endl;
    }
};

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
                std::cout << "Generando matriz disersa.......";
                generateGraphvizFiles(sparseDot(userMatrix), "Matriz_Dispersa");
                break;
            case 3:
                std::cout << "*-------------------* Reporte activos disponibles de un departamento *-------------------*" << std::endl;
                reportActiveDepartment(userMatrix);
                break;
            case 4:
                std::cout << "*-------------------* Reporte activos disponibles de una empresa *-------------------*" << std::endl;
                reportActiveCompany(userMatrix);
                break;
            case 5:
                std::cout << "*-------------------* Reporte transacciones *-------------------*" << std::endl;
                break;
            case 6:
                std::cout << "*-------------------* Reporte activos de un usuario *-------------------*" << std::endl;
                reportActiveUser(userMatrix);
                break;
            case 7:
                std::cout << "*-------------------* Reporte rentados por un usuario *-------------------*" << std::endl;
                reportRentedUser(userMatrix);
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