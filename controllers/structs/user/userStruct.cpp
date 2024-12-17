
#include <iostream>
#include "../../functions/functions.h"
#include "userStruct.h"

#include <algorithm>

userStruct::userStruct(std::string userName, std::string fullName, std::string password, std::string company, std::string country){


    userName = toLowerCase(userName);
    fullName = toLowerCase(fullName);
    company = toLowerCase(company);
    country = toLowerCase(country);

    std::replace(userName.begin(), userName.end(), ' ', '_');
  this->userName = userName;
  this->fullName = fullName;
  this->password = password;
  this->actives = new avlTree();
    this->rentActives = new linkedList();

    std::replace(company.begin(), company.end(), ' ', '_');
    std::replace(country.begin(), country.end(), ' ', '_');

  this->company = company;
  this->country = country;
    this->cell = company+"_"+country;

}
