
#include "circularDot.h"

std::string generateDotCircular(CircularLinkedList* list) {
    std::ostringstream dot;
    dot << "digraph G {\n";
    dot << "  rankdir=LR;\n";
    dot << "  node [shape=circle];\n";

    if (list->head != nullptr) {
        nodeCircular* current = list->head;
        do {
            dot << "  " << current->id << " [label=\"" << current->data->description << "\"];\n";
            dot << "  " << current->id << " -> " << current->next->id << ";\n";
            current = current->next;
        } while (current != list->head);
    }

    dot << "}\n";
    return dot.str();
}