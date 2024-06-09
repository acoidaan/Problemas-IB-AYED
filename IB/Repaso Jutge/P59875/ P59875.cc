// https://jutge.org/problems/P59875_en
// Write a program that reads two numbers x and y, and prints all numbers between x and y (or between y and x), in decreasing order.
// Input consists of two integer numbers x and y.
// Print all integer numbers between x and y (or between y and x), in decreasing order.
#include <iostream>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (x > y) {
    for (int i = x; i >= y; i--) {
    cout << i << endl;
    }
  } else if (y > x) {
     for (int i = y; i >= x; i--) {
    cout << i << endl;
    }
  } else {
    cout << x << endl;
  }
  return 0;
}