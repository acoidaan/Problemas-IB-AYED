#include <iostream>
using namespace std;

int BinaryConvert(int n) {
  return n > 1 ? BinaryConvert(n / 2) * 10 + (n % 2) : n;
}

int main(int argc, char* argv[]) {
  int n = stoi(argv[1]);
  cout << BinaryConvert(n) << endl;
  return 0;
}