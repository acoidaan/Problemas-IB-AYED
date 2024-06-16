#include <iostream>
using namespace std;

int MCM(int a, int b, int div) {
  if ((a < div) || (b < div)) return a * b;
  if (a % div != 0 && b % div != 0) return (MCM(a, b, div + 1));
  int x = a % div == 0 ? a/div : a;
  int y = b % div == 0 ? b/div : b;
  return div * MCM(x, y, div);
}

int main(int argc, char* argv[]) {
  int n1 = stoi(argv[1]);
  int n2 = stoi(argv[2]);
  cout << n1 << ' ' << n2 << endl;
  cout << MCM(n1, n2, 2) << endl;
  return 0;
}