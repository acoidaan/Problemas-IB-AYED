#include "program.h"

int main() {
  DoubleManager manager;
  manager.Add(3.9);
  manager.Add(2.0);
  manager.Add(4.1);

  double closest = manager.Closest(4.1);
  std::cout << "El valor mas cercano a 4.1 es: " << closest << std::endl;

  return 0;
}