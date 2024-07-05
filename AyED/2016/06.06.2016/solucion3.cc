#include <iostream>
#include <vector>
#include <cmath>
#include "../2024/Junio/enunciado.cc"
using namespace std;

// 1.-  Vectores (4 puntos)

// a) (1 puntos) Impleméntese la función recursiva template <>  vector_t<int>::BBR(int i, int d, int x) const que lleva a cabo la búsqueda recursiva de un elemento x dentro del vector invocante, en los extremos i y d del vector.
template <>
int vector_t<int>::BBR(int i, int d, int x) {
  if (i < d) {
    int c = (i + d) / 2;
    if (at(c) == x) return c;
    if (at(c) < x) return BBR(c + 1, d, x);
    if (at(c) > x) return BBR(i, c - 1, x);
  }
}

// b) (1 puntos) Busqueda binario iterativa
template <class T>
int BBI(int i, int d, int x) {
  while (i <= d) {
    int c = (i + d) / 2;
    if (at(c) == x) return c;
    if (at(c) < x) i = c + 1;
    if (at(c) > x) d = c - 1;
  }
  return -1;
}


// c) (1 puntos) Impleméntese la función recursiva template <>  vector_t<double>::BBR(int i, int d, double x) const que lleva a cabo la búsqueda recursiva de un elemento x dentro del vector invocante, en los extremos i y d del vector.



// d) (1 puntos) Impleméntese la función recursiva template <>  vector_t<int>::max(int i, int d) const que lleva a cabo la búsqueda recursiva del elemento máximo dentro del vector invocante, en los extremos i y d del vector.


// 2.- Matrices (3 puntos) Los algoritmos de los siguiente problemas deben recorrer exactamente la subestructura que se especifica.

// a) (0,5 puntos) Implementar un método para la clase matrix_t<double> que cuente el número de elementos distintos de cero que hay en la submatriz triangular superior, sin contar la diagonal, con la premisa de que la matriz es cuadrada.
int matrix_t<double>::NZND(const double EPS = 1e-10) {
  int count = 0;
  for (int i = 1; i <= get_m() - 1; i++) {
    for (int j = i + 1; j <= get_n() - 1; j++) {
      if (fabs(at(i, j) > EPS)) count++;
    }
  }
  return count;
} 


// b) (0,5 puntos)  Implementar un método para la clase matrix_t<double> que cuente el número de elementos menores que cero que hay en la submatriz triangular superior, incluyendo la diagonal, con la premisa de que la matriz es cuadrada.
int matrix_t<double>::MZD(const double EPS = 1e-10) {
  int count = 0;
  for (int i = 1; i <= get_m() - 1; i++) {
    for (int j = i; j <= get_n() - 1; j++) {
      if (at(i, j) < -EPS) count++;
    }
  }
  return count;
}


// c)  (1 punto)  Implementar un método para la clase matrix_t<int> que devuelva   el número de filas que contienen al menos un elemento par.
int matrix_t<double>::CountEvenRow() {
  int count = 0;
  for (int i = 1; i <= get_m(); i++) {
    bool found = false;
    for (int j = 1; j <= get_n() && !found; j++) {
      // if (at(i,j) % 2 == 0) found = true; // descomentado esto
    }
    if (found) count++;
  }
  return count;
}

// d) (1 punto)  Implementar un método para la clase matrix_t<int> que devuelva el número de columnas con más de un elemento distinto de cero.
int matrix_t<int>::CountMZColumn(const double EPS = 1e-10) {
  int count = 0;
  for (int j = 1; j <= get_n() - 1; j++) {
    int lc = 0;
    for (int i = 1; i <= get_m() - 1; i++) {
      if (fabs(at(j, i)) > EPS) lc++;
    }
    if (lc > 1) count++;
  }
  return count;
}


// 3.- Vectores dispersos (3 puntos)

// a) (2 puntos) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_pair_t& b) que devuelve el producto escalar de dos vectores dispersos.
double scalprod(const vector_pair_t& a, const vector_pair_t& b) {
  const int a_sz = a.get_nz();
  const int b_sz = b.get_nz();
  double scalp = 0.0;
  int i = 0, j = 0;

  while (i <= a_sz && j <= b_sz) {
    const int a_inx = a.get_v(i).get_inx();
    const int b_inx = b.get_v(j).get_inx();
    if (a_inx == b_inx) {
      scalp += a.get_v(i++).get_val() * b.get_v(j++).get_val();
    } else if (a_inx < b_inx) i++;
      else j++;
  }
  return scalp;
}


// b) (1 punto) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_t& b) que devuelve el producto escalar de un vector disperso por otro denso.
double scalprod(const vector_pair_t& a, const vector_t& b) {
  const int a_sz = a.get_nz();
  double scalp = 0.0;
  for (int i = 0; i <= a_sz; i++) {
    scalp += a.get_v(i).get_val() * b.get_val(a.get_v(i).get_inx());
  }
  return scalp;
}


double scalprod(const vector_pair_t& a, const vector_pair_t& b) {
  const int a_sz = a.get_nz();
  const int b_sz = b.get_nz();
  double scalp = 0.0;
  int i = 0, j = 0;
  while (i <= a_sz && j <= b_sz) {
    const int a_inx = a.get_v(i).get_inx();
    const int b_inx = b.get_v(j).get_inx();
    if (a_inx  == b_inx) {
      scalp += a.get_v(i++).get_val() * b.get_v(j++).get_val();
    } else if (a_inx < b_inx) i++;
    else j++;
  }
  return scalp;
}

double scalprod(const vector_pair_t& a, const vector_t& b) {
  const int a_sz = a.get_nz();
  double scalp = 0.0;
  for (int i = 0; i <= a_sz; i++) {
    scalp += a.get_v(i).get_val() * b.get_v(a.get_v(i).get_inx());
  }
  return scalp;
}