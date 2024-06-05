#include "programa.h"

int main() {
  std::string number;
  std::getline(std::cin, number);
  if (IsValid(number)) {
    std::cout << "Valido" << std::endl;
  } else {
    std::cout << "No es valido" << std::endl;
  }
  return 0;
}