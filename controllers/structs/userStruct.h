

#ifndef USERSTRUCT_H
#define USERSTRUCT_H

#ifndef USUARIO_H
#define USUARIO_H

#include <string>

struct userStruct {
    std::string userName;
    std::string fullName;
    std::string password;
    // AVL tree activos
    // Lista circular de transacciones

    void imprimirInfo() const;
};

#endif // USUARIO_H

#endif //USERSTRUCT_H
