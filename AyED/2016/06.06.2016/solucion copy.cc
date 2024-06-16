#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 1.-  Vectores (4 puntos)

// a) (1 puntos) Impleméntese la función recursiva template <>  vector_t<int>::BBR(int i, int d, int x) const que lleva a cabo la búsqueda recursiva de un elemento x dentro del vector invocante, en los extremos i y d del vector.

template <>
vector_t<int>::BBR(int i, int d, int x) { // const
  if (i > d) return -1;
  int c = (i + d) / 2;
  if (v_.get_v(c) == x) return c;
  else if (v_.get_v(c) > x) return BBR(i, c - 1, x);
  else if (v_.get_v(c) < x) return BBR(c + 1, d, x);
}

// b) (1 puntos) Busqueda binario iterativa
int BBI(const vector<int>& v, int i, int d, int x) {
  while (i <= d) {
    int c = (i + d) / 2;
    if (v_.get_v(c) == x) return c;
    else if (v_.get_v(c) > x) d = c - 1;
    else if (v_.get_v(c) < x) i = c + 1;
  }
  return -1;
}

// c) (1 puntos) Impleméntese la función recursiva template <>  vector_t<double>::BBR(int i, int d, double x) const que lleva a cabo la búsqueda recursiva de un elemento x dentro del vector invocante, en los extremos i y d del vector.
bool Igual(double a, double b, double eps = 1e-10) {
  return (fabs(a - b) < eps);
}

bool Menor(double a, double b, double eps = 1e-10) {
  return (b - a > eps);
}

int BBR(const vector_t<double>& v, int i, int d, double x) {
  if (i > d) return -1;
  int c = (i + d) / 2;
  if (Igual(v.get_v(c), x)) return c;
  else if (Menor(x, v.get_v(c))) return BBR(v,i, c - 1, x);
  else if(Menor(v.get_v(c), x)) return BBR(v, c + 1, d, x); 
}

// d) (1 puntos) Impleméntese la función recursiva template <>  vector_t<int>::max(int i, int d) const que lleva a cabo la búsqueda recursiva del elemento máximo dentro del vector invocante, en los extremos i y d del vector.
template <>
vector_t<int>::max(const vector_t<int>& v, int i, int d) const {
  assert (i <= d);
  if (i == d) return v.get_v(i);
  return max(v.get_v(i), max(v, i + 1, d))
}

// 2.- Matrices (3 puntos) Los algoritmos de los siguiente problemas deben recorrer exactamente la subestructura que se especifica.

// a) (0,5 puntos) Implementar un método para la clase matrix_t<double> que cuente el número de elementos distintos de cero que hay en la submatriz triangular superior, sin contar la diagonal, con la premisa de que la matriz es cuadrada.
int CuentaNoCeroTSND(double eps) const {
  int count{0};
  for (int i = 1; i <= m_ - 1; i++) {
    for (int j = i + 1; j <= n_; j++) {
      if (fabs(v_[pos(i, j)]) > eps) count++;
    }
  }
  return count;
}

// b) (0,5 puntos)  Implementar un método para la clase matrix_t<double> que cuente el número de elementos menores que cero que hay en la submatriz triangular superior, incluyendo la diagonal, con la premisa de que la matriz es cuadrada.
int CuentaMenorCeroTSD(double eps) const {
  int count{0};
  for (int i = 1; i <= m_; i++) {
    for (int j = i; j <= n; j++) {
      if (v_[pos(i, j)] < -eps) count++; 
    }
  }
  return count;
}


// c)  (1 punto)  Implementar un método para la clase matrix_t<int> que devuelva el número de filas que contienen al menos un elemento par.

// d) (1 punto)  Implementar un método para la clase matrix_t<int> que devuelva el número de columnas con más de un elemento distinto de cero.


// 3.- Vectores dispersos (3 puntos)

// a) (2 puntos) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_pair_t& b) que devuelve el producto escalar de dos vectores dispersos.


// b) (1 punto) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_t& b) que devuelve el producto escalar de un vector disperso por otro denso.
