#include "program.h"
int main() {
  std::string credit_number;
  std::getline(std::cin, credit_number);
  if(IsValid(credit_number)) {
    std::cout << "Valido" << std::endl;
  } else {
    std::cout << "No valido" << std::endl;
  }
  return 0;
}