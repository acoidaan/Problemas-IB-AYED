#include <iostream>
using namespace std;

int SumDigits(int n) {
  return n > 0 ? (n % 10) + SumDigits(n / 10) : 0;
}

int main(int argc, char* argv[]) {
  int n = stoi(argv[1]);
  cout << SumDigits(n) << endl;
  return 0;
}