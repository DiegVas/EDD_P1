#include <string>
#include <sstream>
#include "../dataStructure/avlTree/avlTree.h"
#include "avlDot.h"

void generateDotNodes(avlNode *node, std::stringstream &dotContent);

std::string generateAvlDot(avlTree *tree, std::string title) {
    std::stringstream dotContent;
    dotContent << "digraph AVLTree {\n";
    dotContent << "label=" << title << ";\n";
    dotContent << "    node [shape=circle, style=filled, color=lightblue, fontcolor=black];\n";

    if (tree->root) {
        generateDotNodes(tree->root, dotContent);
    }

    dotContent << "}\n";
    return dotContent.str();
}

void generateDotNodes(avlNode *node, std::stringstream &dotContent) {
    if (!node) return;

    // Representación del nodo con balance factor (opcional)
    dotContent << "    \"" << node->valor << "\" [label=\"" << node->active->name << "\"";
    if( !node->active->isAvailable) dotContent << "color=red";
    dotContent << "];\n";

    // Enlace al nodo izquierdo
    if (node->left) {
        dotContent << "    \"" << node->valor << "\" -> \"" << node->left->valor << "\";\n";
        generateDotNodes(node->left, dotContent);
    }

    // Enlace al nodo derecho
    if (node->right) {
        dotContent << "    \"" << node->valor << "\" -> \"" << node->right->valor << "\";\n";
        generateDotNodes(node->right, dotContent);
    }
}

std::string generateAVLSubGraphDot(avlTree *tree, std::string userName) {

    std::stringstream dotContent;
    dotContent << "subgraph cluster_" << userName << "{\n";
    dotContent << "label = \"" << userName << "\";\n";
    dotContent << "color=black\n";
    dotContent << "    node [shape=circle, style=filled, color=lightblue, fontcolor=black];\n";

    if (tree->root) {
        generateDotNodes(tree->root, dotContent);
    }

    dotContent << "}\n";
    return dotContent.str();
}