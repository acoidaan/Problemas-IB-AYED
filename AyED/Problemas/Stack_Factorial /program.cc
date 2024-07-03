#include <iostream>
using namespace std;
#include "../2024/Junio/enunciado.cc"

unsigned factorial(unsigned n) {
  stack_l_t<unsigned> stack;
  unsigned resultado;
  while (n > 0) {
    stack.push(n--);
  }
  stack.push(1);  // factorial(0)
  while (!stack.empty()) {
    resultado = stack.top(); stack.pop();
    if (!stack.empty()) {
      n = stack.top(); stack.pop();
      stack.push(n * resultado);
    }
  }
  return resultado;
}