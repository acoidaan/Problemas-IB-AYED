#include <iostream>

bool IsGuay(int number) {
  int sum{0}, position{1};
  while (number > 0) {
    if (position % 2 == 0) {
      sum += number % 10;
    }
    number /= 10;
    position++;
  }
  return number % 2 == 0;
}

int main() {
  int number;
  std::cout << "Introduce un numero para saber si es guay o no: ";
  std::cin >> number;
  if (IsGuay(number)) {
    std::cout << number << " es un numero guay." << std::endl;
  } else {
    std::cout << number << " no es un numero guay." << std::endl;
  }
}