#include "programa.h"
bool IsValid(std::string number) {
  if (number.length() <= 4) {
    std::cout << "Numero no valido." << std::endl;
    return false;
  }

  int sum = 0;

  for (int i = number.length() - 1; i >= 0; i--) {
  int position = 1;
    char character = number[i];

    if (character < '0' || character > '9') {
      continue;
    }

    int digit = static_cast<int>(character);

    if (position % 2 == 0) {
      digit *= 2;
      sum += digit / 10 + digit % 10;
    } else {
      sum += digit; 
    }

    position++;
  }
  
  std::cout << sum << std::endl;
  return (sum % 10 == 0);
}
