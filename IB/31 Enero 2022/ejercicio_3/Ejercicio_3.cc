#include <iostream>

bool IsGuay(int number) {
  int sum{0};
  int position{1};
  while (number > 0) {
    if (position % 2 != 0) {
      sum += number % 10;
    }
    number /= 10;
    position++;
  }
  return (sum % 2 == 0);
}

int main() {
  int number;
  std::cout << "Introduce un numero: ";
  std::cin >> number;
  if (IsGuay(number)) {
    std::cout << number << " es GUAY" << std::endl;
  } else {
    std::cout << number << " no es GUAY" << std::endl;
  }
  return 0;
}
