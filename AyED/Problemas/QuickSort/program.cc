// quicksort iterativo
#include <iostream>
using namespace std;
int partir(int *v, int ini, int fin) {
  int i = ini + 1, d = fin, p = v[ini];
  while (i <= d) {
    while (i <= d && v[i] <= p) i++;
    while (i <= d && p <= v[d]) d--;
    if (i < d) swap(v[i++], v[d--]);
  }
  swap(v[ini], v[d]);
  return d;
}

// quicksort recursivo
void OR(int *v, int i, int d) {
  if (i < d) {
    int pivote = partir(v, i, d);
    OR(v, i, pivote - 1);
    OR(v, pivote + 1, d);
  }
}