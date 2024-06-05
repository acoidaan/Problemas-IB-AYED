#include <iostream>
int main() {
  int number;
  std::cin >> number;
  while (number > 0) {
    if (number % 2 != 0) {
      number--;
      continue;
    } else if (number == 50 || number == 51) {
      break;
    } else {
      std::cout << number << " ";
    }
    number--;
  }
  return 0;
}