
#include <algorithm>
#include "avlTree.h"

avlTree::avlTree() {
    this->root = nullptr;
}

void avlTree::insert(activeStruct &activeValue){
	avlNode *newNode = new avlNode(activeValue);
    insertNode(newNode, root);

};

void avlTree::insertNode(avlNode *newNode, avlNode *&rootNode) {
    if (rootNode == nullptr) {
        rootNode = newNode;
        rootNode->balanceF=balanceFactor(root);
        return;
    }

    if (newNode->valor < rootNode->valor) {
        insertNode(newNode, rootNode->left);
    } else {
       insertNode(newNode, rootNode->right);
    }

    rootNode->balanceF=balanceFactor(rootNode);

      if(rootNode->balanceF > 1){
        if(rootNode->right->balanceF < 0){
          return rotateLeftRight(rootNode);
        }else{
            return rotateRight(rootNode);
        }

    }

    if(rootNode->balanceF < -1){
        if(rootNode->left->balanceF > 0)
        {
          return rotateRightLeft(rootNode);
        }
         else
        {
                return rotateLeft(rootNode);
        }
    }



};

int avlTree::maxHeigth(avlNode *node) {
    if (node == nullptr) return 0;

    int left = maxHeigth(node->left);
    int right = maxHeigth(node->right);

    return left > right ? left + 1 : right + 1;
//    return 1 + std::max(maxHeigth(node->left), maxHeigth(node->right));
};

int avlTree::balanceFactor(avlNode *node) {
    return maxHeigth(node->right) - maxHeigth(node->left);
};

void avlTree::rotateRight(avlNode *&node) {
    avlNode *aux = node->right;
    node->right = aux->left;
    aux->left = node;
    node = aux;

    assignBalance(node);
};

void avlTree::rotateLeft(avlNode *&node) {
    avlNode *aux = node->left;
    node->left = aux->right;
    aux->right = node;
    node = aux;

    assignBalance(node);
};

void avlTree::assignBalance(avlNode *&node) {
  	if (node == nullptr) return;
    node->balanceF = balanceFactor(node);
    node->left->balanceF = balanceFactor(node->left);
    node->right->balanceF = balanceFactor(node->right);
};

void avlTree::rotateRightLeft(avlNode *&node) {
    rotateRight(node->left);
    rotateLeft(node);
};

void avlTree::rotateLeftRight(avlNode *&node) {
    rotateLeft(node->right);
    rotateRight(node);
};

avlNode *avlTree::minValueNode(avlNode* &node) {
    avlNode *current = node;

    while (current->right != nullptr) {
        current = current->right;
    }

    return current;
};

void avlTree::deleteNode(std::string id) {
    deleteNode(root, id);
};

void avlTree::deleteNode(avlNode*& node, std::string value) {
  // ! No existe el valor
    if (node == nullptr) return;

    if (value < node->valor) {
        deleteNode(node->left, value);
    } else if (value > node->valor) {
        deleteNode(node->right, value);
    } else {
      if (isSheet(node)) {
          node = nullptr;
        return;
        } else
        if (node->left == nullptr) {
            node = node->right;
        } else if (node->right == nullptr) {
            node = node->left;
        // ! Si tiene dos hijos
        // ? Buscar el nodo mas pequeño del subarbol derecho
        }

        avlNode *aux = minValueNode(node->left);
        node->valor = aux->valor;
        deleteNode(node->left, aux->valor);
        value = aux->valor;

    }

    node->balanceF = balanceFactor(node);

    if (node->balanceF > 1) {
        if (node->right->balanceF < 0) {
            rotateRightLeft(node);
        } else {
            rotateLeft(node);
        }
        return;
    }

    if (node->balanceF < -1) {
        if (node->left->balanceF > 0) {
            rotateLeftRight(node);
        } else {
            rotateRight(node);
        }
        return;
    }
};

bool avlTree::isSheet(avlNode *node) {
    return node->left == nullptr && node->right == nullptr;
};

void avlTree::getNode(std::string id) {
    avlNode *current = root;

    while (current != nullptr) {
        if (current->valor == id) {
            // ! se encontro el nodo
            return;
        }

        if (id < current->valor) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // ! No se encontro el nodo
};

void avlTree::setterNode(std::string id, activeStruct newValue) {
    avlNode *current = root;

    while (current != nullptr) {
        if (current->valor == id) {
            current->valor = newValue.id;
            return;
        }

        if (newValue.id < current->valor) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // ! No se encontro el nodo
};