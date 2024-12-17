//
// Created by HP on 16/12/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#endif //LINKEDLIST_H

#include "../../structs/actives/activeStruct.h"
#include "../../nodes/linkedList/nodeLinked.h"

class linkedList {
public:
    nodeLinked* head;

    linkedList() : head(nullptr) {}

    void addActive(activeStruct *active) {
        nodeLinked* newNode = new nodeLinked(active);
        newNode->next = head;
        head = newNode;
    }

    activeStruct* findActiveById(const std::string id) {
        nodeLinked* current = head;
        while (current != nullptr) {
            if (current->active->id == id) {
                return current->active;
            }
            current = current->next;
        }
        return nullptr;
    }

    void setActiveAvailability(const std::string& id, bool isAvailable, int daysRented) {
        activeStruct* active = findActiveById(id);
        if (active != nullptr) {
            active->isAvailable = isAvailable;
            active->daysRented = daysRented;
        }
    }

    void deleteActive(const std::string& id) {
        if (head == nullptr) return;

        // Si el nodo a eliminar es el primero
        if (head->active->id == id) {
            nodeLinked* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Buscar el nodo a eliminar
        nodeLinked* current = head;
        while (current->next != nullptr && current->next->active->id != id) {
            current = current->next;
        }

        // Si se encontró el nodo
        if (current->next != nullptr) {
            nodeLinked* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }
};
