/*
 * Un número natural se dice que es guay si la suma de los dígitos que están en posiciones
 * impares (empezando a contar por la derecha) es un número par. Por ejemplo, 2 y 679031 son números
 * guay, pero 357199 y 607 no lo son.
 * Escriba un programa que imprima si un número dado es guay o no. La salida del programa debiera ser “N
 * es GUAY” o bien “N no es GUAY”.
*/
#include <iostream>
using namespace std;

bool IsGuay(int number) {
  int sum{0}, position{1};
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
  int n;
  cin >> n;
  if (IsGuay(n)) cout << "guay" << endl;
  else cout << "no guay" << endl;
  return 0;
}
