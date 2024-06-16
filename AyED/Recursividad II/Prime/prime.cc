#include "../iostream"
#include "../cmath"
#include "../matrix_t.hpp"

using namespace std;

bool IsPrime(int i, int div) {
  if (i == div) return true;
  return (i % div == 0) ? false : IsPrime(i, div + 1) ;
}

int main(int argc, char* argv[]) {
  int n = stoi(argv[1]);
  if (IsPrime(n, 2)) cout << "primo" << endl;
  else cout << "no primo" << endl;
  return 0; 
}