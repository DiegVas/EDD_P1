#include <string>
#include "../dataStructure/avlTree/avlTree.h"

#ifndef AVLDOT_H
#define AVLDOT_H

std::string generateAvlDot(avlTree* tree, std::string title);
std::string generateAVLSubGraphDot(avlTree* tree, std::string userName);

#endif //AVLDOT_H
