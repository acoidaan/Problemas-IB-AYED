#include <iostream>
using namespace std;
int BBR(int v[], int i, int d, const int x) {
  if (i > d) return -1;
  else {
    int c = (i + d) / 2;
    if (v[c] == x) return c;
    else if (v[c] < x) return BBR(v, c + 1, d, x);
    else if (x < v[c]) return BBR(v, i, d - 1, x);
  }
}