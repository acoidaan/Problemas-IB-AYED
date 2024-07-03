#include <iostream>
using namespace std;

int factorial(int n) {
  return n > 0 ? n * factorial(n - 1) : 1;
}