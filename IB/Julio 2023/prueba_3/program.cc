#include "program.h"
bool IsValid(std::string credit_number) {
  int sum{0}, position{1};
  unsigned int digits = credit_number.length();

  if (digits <= 4) {
    return false;
  }

  for (int i = digits - 1; i >= 0; i--) {
    if (!std::isdigit(credit_number[i])) {
      continue;
    }

    int digit = credit_number[i] - '0';

    if (position % 2 == 0) {
      digit *= 2;
      if (digit > 9) {
        digit = digit - 9;
      }
    }
    sum += digit;
    position++;
  }
  
  std::cout << sum << std::endl;
  return sum % 10 == 0;
}