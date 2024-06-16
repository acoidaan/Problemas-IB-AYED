#include <iostream>
#include <cassert>
using namespace std;

// a) (0,5 puntos) Impleméntese dos procedimientos, uno de ellos recursivo, para imprimir el contenido de una lista enlazada de enteros, de acuerdo con la descripción de clase dadas anteriormente.
template <class T>
void sll_t<int>::writeIterative(ostream& os) const {
  write1(head_, os);
}

template <class T>
void sll_t<int>::write1(sll_node_t<int>* node, ostream& os) const {
  if (node != NULL) {
    os << node->get_data();
    write1(node->get_next(), os);
  }
}
// b) (0,5 puntos) Impleméntese dos procedimientos, uno de ellos recursivo, para imprimir al revés el contenido de una lista enlazada de enteros, de acuerdo con la descripción de clases dada anteriormente.
template <class T>
void sll_t<int>::writeRecursive(ostream& os) const {
  write2(head_, os);
}

template <class T>
void sll_t<int>::write2(sll_node_t* node, ostream& os) const {
  if (node != NULL) {
    write2(node->get_next(), os);
    os << node->get_data();
  }
}

// c) (1 punto) Impleméntese un procedimiento iterativo para imprimir al revés el contenido de una lista enlazada de enteros, utilizando una pila auxiliar, de acuerdo con la descripción de clases dada anteriormente.
template <class T>
void sll_t<int>::writeReverseStack(ostream& os) {
  stack_t<int> stack;
  sll_node_t<int>* aux = head_;
  while ( != NULL) {
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
int sll_t<double>::cuenta(double val, double eps) const {
  sll_node_t<double>* aux = head_;
  int count = 0;
  while (aux != NULL) {
    if (fabs(aux->get_data() - val) < eps) count++;
    aux = aux->get_next();
  }
  return count;
}


// 2.- Matrices (2 puntos) Los algoritmos de los siguiente problemas deben recorrer exactamente la subestructura que se especifica.

// a) (0,5 puntos) Implementar un método para la clase matrix_t<double> que cuente el número de ceros que hay en la submatriz triangular inferior, sin contar la diagonal, con la premisa de que la matriz es cuadrada.
int CuentaCeroTIND(double eps) const {
  int count{0};
  for (int i = 2; i <= m_; i++) {
    for (int j = 1; j <= n_; j++) {
      if (fabs(v_[pos(i,j)]) < eps) count++;
    }
  }
  return count;
} 

// b) (0,5 puntos)  Implementar un método para la clase matrix_t<double> que cuente el número de elementos mayores que cero que hay en la submatriz triangular inferior, incluyendo la diagonal, con la premisa de que la matriz es cuadrada.
int CuentaMayorCeroTID(double eps) const {
  int count{0};
  for (int i = 1; i <= m_; i++) {
    for (int j = 1; j <= i; j++) {
      if (v_[pos(i,j)] > eps) count++;
    }
  }
}

// c)  (0,5 puntos)  Implementar un método para la clase matrix_t<int> que devuelva la fila que alberga la última ocurrencia del mayor valor de la diagonal principal, con la premisa de que la matriz es cuadrada.
int FilaMaxDP(void) const {
  int max_inx = 1;
  int max_val = v_[pos(1, 1)];

  for (int i = 2; i <= m_; i++) {
    if (v_[pos(i, i)] > max_val) {
      max_inx = 1;
      max_val = v_[pos(i, i)];
    }
  }
  return max_inx;
}

// d) (0,5 puntos)  Implementar un método para la clase matrix_t<int> que devuelva la columna que alberga la primera ocurrencia del mayor valor de la diagonal secundaria, con la premisa de que la matriz es cuadrada.
int ColMaxDP(void) const {
  int max_inx = n_;
  int max_val = v_[pos(1, n_)];

  for (int i = 2; i <= m_; i++) {
    if (v_[pos(i, n_ - i + 1)] > max_val) {
      max_val = v_pos[(i, n - i + 1)];
      max_inx = i;
    }
  }
  return max_inx;
}


// 3.- Vectores (5 puntos)

// a) (2 puntos) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_pair_t& b) que devuelve el producto escalar de dos vectores dispersos.
double scalprod(const vector_pair_t& a, const vector_pair_t& b) {
  const int a_sz = a.get_sz();
  const int b_sz = b.get_sz();

  int i = 0, j = 0;
  double scalp = 0.0;
  while (i < a_sz && j < b_sz) {
    const int a_inx = a.get_v(i).get_inx();
    const int b_inx = b.get_v(i).get_inx();
    if (a_inx == b_inx) {
      scalp += a.get_v(i).get_val(i++) * b.get_v(i).get_val(j++);
    } else {
      if (a_inx < b_inx) i++;
      else j++;
    }
  }
  return scalp;
}

// b) (1 punto) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_t& b) que devuelve el producto escalar de un vector disperso por otro denso.
double scalprod(const vector_pair_t& a, const vector_t& b) {
  int a_sz = a.get_sz();
  double scalp = 0.0;

  for (int i = 0; i < a_sz; i++) {
    scalp += a.get_v(i).get_val() * b.get_val(get_v(i).get_inx());
  }
  return scalp;
}


// c) (2 puntos) Implementar el procedimiento void vector_t::fusion(const vector_t& a, const vector_t& b)que hace que el contenido del vector invocante sea un vector ordenado creado a partir de la fusión de los vectores ordenados a y b. Los vectores a y b. En este caso particular se sabe que el último elemento del vector a y el último elemento del vector b no formarán parte de vector ordenado, puesto que son elementos centinela. Formalmente estos dos elementos tiene valor +infinito. El procedimiento a construir sólo debe tener una única estructura iterativa tipo for, y una única estructura selectiva tipo if-else.
