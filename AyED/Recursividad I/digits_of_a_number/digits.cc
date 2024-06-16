#include <iostream>
using namespace std;

int Count (int n) {
  return n > 0 ? 1 + Count(n / 10) : 0;
}

int main(int argc, char* argv[]) {
  int n = stoi(argv[1]);
  cout << Count(n) << endl;
  return 0;
}