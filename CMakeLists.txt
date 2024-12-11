cmake_minimum_required(VERSION 3.30)
project(EDD_P1_202300638)

set(CMAKE_CXX_STANDARD 20)

add_executable(EDD_P1_202300638 main.cpp
        content/admin/admin.h
        content/admin/admin.cpp
        controllers/sparseMatrix.h
        controllers/sparseMatrix.cpp
        controllers/nodes/NodeMatrix.h
        controllers/nodes/nodeMatrix.cpp
        controllers/functions/toLowerCase.h
        controllers/functions/toLowerCase.cpp
)
