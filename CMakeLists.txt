cmake_minimum_required(VERSION 3.30)
project(EDD_P1_202300638)

set(CMAKE_CXX_STANDARD 20)

add_executable(EDD_P1_202300638 main.cpp
        content/admin/admin.h
        content/admin/admin.cpp
        controllers/dataStructure/sparseMatrix/sparseMatrix.h
        controllers/dataStructure/sparseMatrix/sparseMatrix.cpp
        controllers/nodes/disperseMatrix/nodeMatrix.h
        controllers/nodes/disperseMatrix/nodeMatrix.cpp
        controllers/functions/functions.h
        controllers/functions/functions.cpp
        controllers/dataStructure/avlTree/avlTree.h
        controllers/dataStructure/avlTree/avlTree.cpp
        controllers/nodes/avl/avlNode.h
        controllers/nodes/avl/avlNode.cpp
        controllers/structs/activeStruct.h
        controllers/structs/activeStruct.cpp
        controllers/structs/userStruct.cpp
        controllers/structs/userStruct.h
        controllers/graph/graphGenerator.cpp
        controllers/graph/sparseDot.cpp
        controllers/graph/sparseDot.h
        controllers/graph/graphGenerator.h
)
