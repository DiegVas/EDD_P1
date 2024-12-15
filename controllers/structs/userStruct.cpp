
#include <iostream>
#include "../functions/functions.h"
#include "userStruct.h"

userStruct::userStruct(std::string userName, std::string fullName, std::string password, std::string company, std::string country){

    userName = toLowerCase(userName);
    fullName = toLowerCase(fullName);
    company = toLowerCase(company);
    country = toLowerCase(country);

  this->userName = userName;
  this->fullName = fullName;
  this->password = password;
  this->actives = new avlTree();
  this->company = company;
  this->country = country;
    this->cell = company+"_"+country;

}