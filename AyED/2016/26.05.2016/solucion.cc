#include <iostream>
#include <cassert>
using namespace std;

// a) (0,5 puntos) Impleméntese dos procedimientos, uno de ellos recursivo, para imprimir el contenido de una lista enlazada de enteros, de acuerdo con la descripción de clase dadas anteriormente.
template <>
ostream& sll_t<int>::write(ostream& os) const {
  write(head_, os);
}

template <>
ostream& sll_t<int>::write(sll_node_t<int>* node, ostream& os) const {
  if (node != NULL) {
    write(node->get_next(), os);
    os << node->get_data() << endl;
  }
}

// b) (0,5 puntos) Impleméntese dos procedimientos, uno de ellos iterativo, para imprimir al revés el contenido de una lista enlazada de enteros, de acuerdo con la descripción de clases dada anteriormente.
template <>
ostream& sll_t<int>::write(ostream& os) const {
  write(head_, os);
}

template <>
ostream& sll_t<int>::write(sll_node_t<int>* node, ostream& os) const {
  if (node != NULL) {
    os << node->get_data() << endl;
    write(node->get_next(), os);
  }
}

// c) (1 punto) Impleméntese un procedimiento iterativo para imprimir al revés el contenido de una lista enlazada de enteros, utilizando una pila auxiliar, de acuerdo con la descripción de clases dada anteriormente.

template <>
ostream& sll_t<int>::write(ostream& os) const {
  stack_t<int> stack;

  new sll_node_t<int>* aux = head_;
  while (aux != NULL) {
    stack.push(aux)
    aux = aux->get_next();
  }
  
  while(!stack.empty()) {
    os << stack.top() << endl;
    stack.pop();
  }
}

// d) (1 punto) Impleméntese el procedimiento template <> int sll_t<double>::cuenta(double val, double eps) const que cuenta el número de ocurrencias del elemento val dentro de una lista enlazada.

template <>
int sll_t<double>::cuenta(double val, double eps) const {
  new sll_node_t<int>* aux = head_;
  int counter = 0;

  while (aux != NULL) {
    const double lval =  aux->get_data();
    if (fabs((lval - val)) < eps) counter++;
    aux = aux->get_next();
  }
  return counter;
}

// 2.- Matrices (2 puntos) Los algoritmos de los siguiente problemas deben recorrer exactamente la subestructura que se especifica.

// a) (0,5 puntos) Implementar un método para la clase matrix_t<double> que cuente el número de ceros que hay en la submatriz triangular inferior, sin contar la diagonal, con la premisa de que la matriz es cuadrada.

double count_zero_TIND(double eps) const {
  int count = 0;
  
  for (int i = 2; i <= m_; i++) {
    for (int j = 1; j <= i - 1; j++) {
      if (fabs(v_[pos(i,j)]) < eps) count++;
    }
  }
  return count;
}

// b) (0,5 puntos)  Implementar un método para la clase matrix_t<double> que cuente el número de elementos mayores que cero que hay en la submatriz triangular inferior, incluyendo la diagonal, con la premisa de que la matriz es cuadrada.

double greater_zero_TID(double eps) const {
  int count = 0;

  for (int i = 1; i <= m_, i++) {
    for (int j = 1; j <= i; j++) {
      if (v_pos[i,j] > eps) count++;
    }
  }
  return count;
}

// c)  (0,5 puntos)  Implementar un método para la clase matrix_t<int> que devuelva la fila que alberga la última ocurrencia del mayor valor de la diagonal principal, con la premisa de que la matriz es cuadrada.

int fila_max_DP(void) const {
  int max_inx = 1;
  int max_val = v_[pos(1,1)];
  for (int i = 2; i <= m_; i++) {
    if (v_[pos(i,i)] >= max_val) {
      max_inx = i;
      max_val = v_[pos(i,i)];
    }
    return max_inx;
  }
}

// d) (0,5 puntos)  Implementar un método para la clase matrix_t<int> que devuelva la columna que alberga la primera ocurrencia del mayor valor de la diagonal principal, con la premisa de que la matriz es cuadrada.
int columna_max_DP(void) const {
  int max_col = 1;
  int max_val = v_[pos(1,1)];
  for (int i = 2; i <= m_; i++) {
    if (v_[pos(i,i)] >= max_val) {
      max_col = i;
      max_val = v_[pos(i,i)];
    }
  }
  return max_col;
}

// 3.- Vectores (5 puntos)

// a) (2 puntos) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_pair_t& b) que devuelve el producto escalar de dos vectores dispersos.

double scalprod(const vector_pait_t& a, const vector_pair_t& b) {
  const int a_sz = a.get_sz();
  const int b_sz = b.get_sz();

  int i = 0, j = 0;
  double scalp = 0.0;
  while((i < a_sz) && (j < b_sz)) {
    const int a_inx = a.get_v(i).get_inx();
    const int b_inx = b.get_v(i).get_inx();
    if (a_inx == b_inx) {
      scalp += a.get_v(i++).get_val() * b.get_v(j++).get_val();
    } else {
      if (a_inx < b_inx) i++;
      else j++;
    }
  }
  return scalp;
}

// b) (1 punto) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_t& b) que devuelve el producto escalar de un vector disperso por otro denso.
double scalprod(const vector_pair_t& a, const vector_t& b) {
  const int a_sz = a.get_sz();
  double scalp = 0.0;

  for (int i = 0; i < a_sz; i++) {
    scalp += a.get_v(i).get_val() * b.get_val(get_v(i).get_inx());
  }
  return scalp;
}

// c) (2 puntos) Implementar el procedimiento void vector_t::fusion(const vector_t& a, const vector_t& b)que hace que el contenido del vector invocante sea un vector ordenado creado a partir de la fusión de los vectores ordenados a y b. Los vectores a y b. En este caso particular se sabe que el último elemento del vector a y el último elemento del vector b no formarán parte de vector ordenado, puesto que son elementos centinela. Formalmente estos dos elementos tiene valor +infinito. El procedimiento a construir sólo debe tener una única estructura iterativa tipo for, y una única estructura selectiva tipo if-else.

void vector_t::fusion(const vector_t& a, const vector_t& b) {
  resize(a.get_sz() - 1 + b.get_sz() - 1);
  int i = 0, j = 0;

  for (int k = 0; k < sz_; k++) {
    if (a.get_v(i) < b.get_v(j)) set_v(k, a.get_v(i++));
    else set_v(k, b.get_v(j++));
  }
}