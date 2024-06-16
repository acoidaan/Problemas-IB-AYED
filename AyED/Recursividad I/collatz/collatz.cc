#include <iostream>
using namespace std;

int Collatz(int n) {
  if (n == 1) return 1;
  else return n % 2 == 0 ? 1 + Collatz(n / 2) : 1 + Collatz(3 * n + 1);
}

int main(int argc, char* argv[]) {
  int n = stoi(argv[1]);
  cout << Collatz(n) << endl;
  return 0;
}