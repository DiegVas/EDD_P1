#include "linkedDot.h"

std::string generateLinkedListDot(nodeLinked* head) {
    std::stringstream dotContent;
    dotContent << "digraph LinkedList {\n";
    dotContent << "    node [shape=record];\n";

    nodeLinked* current = head;
    while (current != nullptr) {
        dotContent << "    \"" << current << "\" [label=\"{" << current->active->name << "}\"];\n";
        if (current->next != nullptr) {
            dotContent << "    \"" << current << "\" -> \"" << current->next << "\";\n";
        }
        current = current->next;
    }

    dotContent << "}\n";
    return dotContent.str();
}