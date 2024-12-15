

#ifndef ACTIVESTRUCT_H
#define ACTIVESTRUCT_H
#include <string>

class activeStruct
{
public:
  std::string id;
  std::string name;
  std::string description;
  bool isAvailable;

  activeStruct(std::string name, std::string description);
  void setter(std::string name, std::string description, bool isAvailable);
};

#endif //ACTIVESTRUCT_H
