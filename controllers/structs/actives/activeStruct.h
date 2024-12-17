

#ifndef ACTIVESTRUCT_H
#define ACTIVESTRUCT_H

#include <string>


class activeStruct
{
public:
  std::string id;
  std::string name;
  std::string description;
  std::string userPropety;
  int daysRented;
  bool isAvailable;

  activeStruct(std::string name, std::string description, std::string userPropety);
  void setter(std::string name, std::string description, bool isAvailable);
};

#endif //ACTIVESTRUCT_H
