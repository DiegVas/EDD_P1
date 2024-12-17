#include "activeStruct.h"

#include <algorithm>
#include <string>
#include <random>
#include "../../functions/functions.h"



activeStruct::activeStruct(std::string name, std::string description, std::string userPropety)
{
    std::replace(name.begin(), name.end(), ' ', '_');
    this->name = name;
    this->description = description;
    this->id = generateRandomId();
    this->isAvailable = true;
    this->userPropety = userPropety;
    this->daysRented = 0;
}

void activeStruct::setter(std::string name, std::string description, bool isAvailable)
{
    this->name = name;
    this->description = description;
    this->isAvailable = isAvailable;
}


