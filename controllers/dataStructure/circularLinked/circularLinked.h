//
// Created by HP on 17/12/2024.
//

#ifndef CIRCULARLINKED_H
#define CIRCULARLINKED_H
#include "../../functions/functions.h"
#include "../../structs/actives/activeStruct.h"

class nodeCircular {
public:
    activeStruct* data;
    std::string id;
    std::string userInformation;
    std::string activeInformation;
    std::string description;
    nodeCircular* next;

    nodeCircular(activeStruct* data,std::string userInformation,std::string userPropety, std::string description) : data(data), next(nullptr) {
      this->data = data;
        this->activeInformation = userPropety;
        this->userInformation = userInformation;
        this->description = description;
        this->id = generateRandomId();
    }
};


class CircularLinkedList {

public:
    nodeCircular* head;
    nodeCircular* tail;
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    void append(nodeCircular* data) {
        nodeCircular* newNode = data;
        if (!head) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void display() {
        if (!head) return;
        nodeCircular* current = head;
        do {
            current = current->next;
        } while (current != head);
    }

    ~CircularLinkedList() {
        if (!head) return;
        nodeCircular* current = head;
        do {
            nodeCircular* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        head = nullptr;
        tail = nullptr;
    }
};



#endif //CIRCULARLINKED_H
