#include <iostream>
using namespace std;

int MCD(int a, int b, int div) {
  if (a < div || b < div) return 1;
  return (a % div == 0 && b % div == 0) ? div * MCD(a/div, b/div, div) : MCD(a, b, div + 1);
}

int main(int argc, char* argv[]) {
  int n1 = stoi(argv[1]);
  int n2 = stoi(argv[2]);
  cout << MCD(n1, n2, 2) << endl;
  return 0;
}