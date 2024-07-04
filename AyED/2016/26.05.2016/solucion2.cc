#include <iostream>
#include <cassert>
#include "../2024/Junio/enunciado.cc"
using namespace std;

// a) (0,5 puntos) Impleméntese dos procedimientos, uno de ellos recursivo, para imprimir el contenido de una lista enlazada de enteros, de acuerdo con la descripción de clase dadas anteriormente.
void sll_t<int>::WriteDirectR(void) {
  write1(head_, os);
}

void write1(sll_node_t<int>* node, ostream& os) {
  if (node != NULL) {
    os << node->get_data();
    write1(node->get_next());
  }
}


// b) (0,5 puntos) Impleméntese dos procedimientos, uno de ellos recursivo, para imprimir al revés el contenido de una lista enlazada de enteros, de acuerdo con la descripción de clases dada anteriormente.
void sll_t<int>::WriteReverseR(void) {
  write2(head_, os);
}

void write2(sll_node_t<int>* node, ostream& os) {
  if (node != NULL) {
    write2(node->get_next(), os);
    os << node->get_data();
  }
}


// c) (1 punto) Impleméntese un procedimiento iterativo para imprimir al revés el contenido de una lista enlazada de enteros, utilizando una pila auxiliar, de acuerdo con la descripción de clases dada anteriormente.
void WriteDirectI(void) {
  stack_l_t<int> stack;
  sll_node_t<T>* aux = get_head();
  while (aux != NULL) {
    stack.push(aux->get_data());
    aux = aux->get_next();
  }
  while (!stack.empty()) {
    os << stack.top();
    stack.pop();
  }
}

// d) (1 punto) Impleméntese el procedimiento template <> int sll_t<double>::cuenta(double val, double eps) const que cuenta el número de ocurrencias del elemento val dentro de una lista enlazada.
template <>
sll_t<double>::cuenta(double val, double eps) {
  int count = 0;
  sll_node_t<double>* aux = get_head();
  while (aux != NULL) {
    if (fabs(aux->get_data() - val) < eps) count++;
    aux = aux->get_next();
  }
  return count;
}


// 2.- Matrices (2 puntos) Los algoritmos de los siguiente problemas deben recorrer exactamente la subestructura que se especifica.

// a) (0,5 puntos) Implementar un método para la clase matrix_t<double> que cuente el número de ceros que hay en la submatriz triangular inferior, sin contar la diagonal, con la premisa de que la matriz es cuadrada. // a21, a31, a32
int matrix_t<double>::CountZTIND() {
  int count = 0;
  for (int i = 2; i <= get_m(); i++) {
    for (int j = 1; j <= get_n() - 1; j++) {
      if (fabs(at(i, j)) < eps) count++;
    }
  }
  return count;
}

// b) (0,5 puntos)  Implementar un método para la clase matrix_t<double> que cuente el número de elementos mayores que cero que hay en la submatriz triangular inferior, incluyendo la diagonal, con la premisa de que la matriz es cuadrada.
// a11, a21, a22, a31, a32, a33
int matrix_t<double>::CountMZTID() {
  int count = 0;
  for (int i = 1; i <= get_m(); i++) {
    for (int j = 1; j <= i; j++) {
      if (at(i, j) > eps) count++;
    }
  }
  return count;
}

// c)  (0,5 puntos)  Implementar un método para la clase matrix_t<int> que devuelva la fila que alberga la última ocurrencia del mayor valor de la diagonal principal, con la premisa de que la matriz es cuadrada.
int matrix_t<int>::UFMVDP() {
  int max_inx = 1;
  int max_val = at(1, 1);

  for (int i = 2; i <= get_m(); i++) {
    if (at(i, i) >= max_val) {
      max_inx = i;
      max_val = at(i, i);
    }
  }
  return max_inx;
}


// d) (0,5 puntos)  Implementar un método para la clase matrix_t<int> que devuelva la columna que alberga la primera ocurrencia del mayor valor de la diagonal secundaria, con la premisa de que la matriz es cuadrada. 
int matrix_t<int>::PCMVDP() {
  int max_inx = n_;
  int max_val = at(1, n_);
  for (int i = 2; i <= m_; i++) {
    if (at(i, n_ - i + 1) > max_val) {
      max_inx = n_ - i + 1;
      max_val = at(i, n_ - 1 + 1);
    }
  }
  return max_inx;
}


// 3.- Vectores (5 puntos)

// a) (2 puntos) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_pair_t& b) que devuelve el producto escalar de dos vectores dispersos.


// b) (1 punto) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_t& b) que devuelve el producto escalar de un vector disperso por otro denso.


// c) (2 puntos) Implementar el procedimiento void vector_t::fusion(const vector_t& a, const vector_t& b)que hace que el contenido del vector invocante sea un vector ordenado creado a partir de la fusión de los vectores ordenados a y b. Los vectores a y b. En este caso particular se sabe que el último elemento del vector a y el último elemento del vector b no formarán parte de vector ordenado, puesto que son elementos centinela. Formalmente estos dos elementos tiene valor +infinito. El procedimiento a construir sólo debe tener una única estructura iterativa tipo for, y una única estructura selectiva tipo if-else.
