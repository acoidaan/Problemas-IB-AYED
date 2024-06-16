#include <iostream>
using namespace std;

int Factorial(int n) {
  if (n == 0) return 1;
  else return n * Factorial(n - 1);
}

int main(int argc, char* argv[]) {
  int n = stoi(argv[1]);
  cout << Factorial(n) << endl;
  return 0;
}