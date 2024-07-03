#include <iostream>
using namespace std;
int collatz(int n) {
  if (n == 1) return 1;
  else return (n % 2 == 0) ? 1 + collatz(n / 2) :  1 + collatz(3 * n + 1);
}