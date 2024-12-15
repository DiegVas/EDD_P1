#include "activeStruct.h"
#include <string>
#include <random>
#include "../functions/functions.h"



activeStruct::activeStruct(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
    this->id = generateRandomId();
    this->isAvailable = true;

}

void activeStruct::setter(std::string name, std::string description, bool isAvailable)
{
    this->name = name;
    this->description = description;
    this->isAvailable = isAvailable;
}


