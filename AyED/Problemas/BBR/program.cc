#include <iostream>
using namespace std;
int BBR(int v[], int i, int d, int x) {
  if (i > d) return -1;
  int c = (i + d) / 2;
  if (v[c] == x) return c;
  if (v[c] < x) return BBR(v, c + 1, d, x);
  if (x < v[c]) return BBR(v, i, c - 1, x); 
}