
#include <iostream>
#include "userMenu.h";

#include <chrono>

void idsPrintTree(avlNode *node, bool isAvailablePrint = true) {
    if (node == nullptr) return;

    // Procesa el nodo actual
    if (node->active->isAvailable == isAvailablePrint) std::cout << "ID: " << node->valor << "; Nombre: " << node->active->name << std::endl;

    // Recorre el subárbol izquierdo
    idsPrintTree(node->left);

    // Recorre el subárbol derecho
    idsPrintTree(node->right);
}


void show_UserMenu()
{

    std::cout << "//////////////// Bienvenido ////////////////" << std::endl;
    std::cout << "*-------------------* MENU *-------------------*" << std::endl;
    std::cout << "[1]. Agregar activo" << std::endl;
    std::cout << "[2]. Eliminar activo" << std::endl;
    std::cout << "[3]. Modificar activos" << std::endl;
    std::cout << "[4]. Rentar activo" << std::endl;
    std::cout << "[5]. Activos rentados" << std::endl;
    std::cout << "[6]. Mis activos rentados" << std::endl;
    std::cout << "[7]. Salir" << std::endl;

    std::cout << "Ingrese una opcion:  ";
}

void addActive(userStruct *user,linkedList *activeList)
{
    std::string nameActive, description;
    std::cout << "Ingrese el nombre del activo: ";
    std::cin >> nameActive;
    std::cout << "Ingrese la descripcion del activo: ";
    std::cin >> description;
    try
    {
        activeStruct* active = new activeStruct(nameActive, description, user->userName);
        user->actives->insert(active, activeList);
    }
    catch (...)
    {
        std::cout << "Error al crear el activo" << std::endl;
    }

    std::cout << "Activo agregado con exito" << std::endl;
    std::cout << std::endl;



}

void deleteActive(avlTree* activeTree, linkedList *activeList)
{
    std::string idActive;
    std::cout << "------------------- Eliminar activo -------------------" << std::endl;

    idsPrintTree(activeTree->root);

    std::cout << "Ingrese el ID del activo a eliminar: ";
    std::cin >> idActive;

    try
    {
        activeTree->deleteNode(idActive, activeList);
    }
    catch (...)
    {
        std::cout << "Error al eliminar el activo" << std::endl;
    }

    std::cout << "Activo eliminado con exito" << std::endl;
    std::cout << std::endl;
}

void setterActive(avlTree* activeTree, userStruct *user, linkedList *activeList)
{
    std::string idActive, nameActive, description;
    std::cout << "------------------- Modificar activo -------------------" << std::endl;

    idsPrintTree(activeTree->root);

    std::cout << "Ingrese el ID del activo a modificar: ";
    std::cin >> idActive;

    std::cout << "Ingrese el nuevo nombre del activo: ";
    std::cin >> nameActive;
    std::cout << "Ingrese la nueva descripcion del activo: ";
    std::cin >> description;
    activeStruct *active = activeList->findActiveById(idActive);
    if (active == nullptr)
    {
        std::cout << "Activo no encontrado" << std::endl;
        return;
    }
        activeTree->setterNode(idActive, nameActive, description,active);
        std::cout << "Activo modificado con exito" << std::endl;


    std::cout << std::endl;
}

void rentActive(linkedList *activeList, userStruct *user, CircularLinkedList *circularList)
{
    std::string idActive;
    int days;
    std::cout << "------------------- Rentar activo -------------------" << std::endl;

    nodeLinked *aux = activeList->head;
    while (aux != nullptr)
    {
        if (aux->active->isAvailable) std::cout << "ID: " << aux->active->id << "; Nombre: " << aux->active->name << std::endl;
        aux = aux->next;
    }

    std::cout << "Ingrese el ID del activo a rentar: ";
    std::cin >> idActive;
    std::cout << "Ingrese los dias a rentar: ";
    std::cin >> days;

    activeStruct *active = activeList->findActiveById(idActive);
    if (active == nullptr)
    {
        std::cout << "Activo no encontrado" << std::endl;
        return;
    }


    activeList->setActiveAvailability(idActive, false, days);
    user->rentActives->addActive(activeList->findActiveById(idActive));
    circularList->append(new nodeCircular(activeList->findActiveById(idActive), user->userName, user->rentActives->findActiveById(idActive)->userPropety, "Activo rentado: " + user->userName));


}

void activesRenter(userStruct *user, CircularLinkedList *circularList)
{
    std::cout << "------------------- Activos rentados -------------------" << std::endl;
    int choice = 0;
    nodeLinked *aux = user->rentActives->head;
    while (aux != nullptr)
    {
        std::cout << "ID: " << aux->active->id << "; Nombre: " << aux->active->name << "Dias rentados: " << aux->active->daysRented << std::endl;
        aux = aux->next;
    }
    std::cout << std::endl;

    while (choice != 2)
    {
        std::cout << "[1]. Devolver activo" << std::endl;
        std::cout << "[2]. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string idActive;
            std::cout << "Ingrese el ID del activo a devolver: ";
            std::cin >> idActive;
            user->rentActives->setActiveAvailability(idActive, true, 0);
            circularList->append(new nodeCircular(user->rentActives->findActiveById(idActive), user->userName, user->rentActives->findActiveById(idActive)->userPropety, "Activo devuelto"));
            user->rentActives->deleteActive(idActive);
            break;
        }
    }

};

void myActivesRenter(userStruct* user)
{
    std::cout << "------------------- Mis activos rentados -------------------" << std::endl;
    idsPrintTree(user->actives->root, false);
    std::cout << std::endl;
};

void userMenu(nodeMatrix* userMatrix, linkedList *activeList, CircularLinkedList *circularList)
{
    int choice;

    do {
        show_UserMenu();
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
        case 1:
            addActive(userMatrix->user, activeList);
            break;
        case 2:
            deleteActive(userMatrix->user->actives, activeList);
            break;
        case 3:
            setterActive(userMatrix->user->actives, userMatrix->user, activeList);
            break;
        case 4:
            rentActive(activeList, userMatrix->user, circularList);
            break;
        case 5:
            activesRenter(userMatrix->user, circularList);
            break;
        case 6:
            myActivesRenter(userMatrix->user);
            break;
        case 7:
            std::cout << "Nos vemos!." << std::endl;
            break;
        default:
            std::cout << "Por favor ingrese una opcion valida" << std::endl;
        }

    } while (choice != 7);
}


