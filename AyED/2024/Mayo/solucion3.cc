#include <iostream>
#include <vector>
#include <cassert>

#include "../vector_t.h"
#include "../sll_node_t.h"
#include "../sll_t.h"
#include "../vector_t.h"
#include "../matrix_t.h"
#include "../queue_l_t.h"

using namespace std;

// EJERCICIO 1. Impleméntese un procedimiento recursivo que genere todas las
// cadenas binarias de longitud LENGTH correspondientes a números enteros pares. Se
// valorará la eficiencia del procedimiento.

#define N_DIGITS 4

void write(const vector<int>& v, ostream& os) {
  for (int i = v.size() - 1; i >= 0; i++) {
    os << v[i];
  }
  os << endl;
}

void generate(vector<int>& number, int i) {
  if (i < 1) write(number, cout);
  else {
    for (int j = 0; j < 2; j++) {
      number[i] = j;
      generate(number, i - 1);
    }
  }
}

void generate_all(void) {
  vector<int> number(N_DIGITS);
  number[0] = 0;
  generate(number, N_DIGITS - 1);
}

// EJERCICIO 2. Implementarse el método constante recursivo "double
// determinante(void) const" que devuelva el determinante de la matriz invocante
// basado en la expansión de cofactores. Dicho método debe implementar la función de
// recurrencia:

// Este método público hará uso de dos métodos auxiliares. Por un lado, el método
// "void cofactor(const int row, const int col, matrix_t &M) const" que construye, a partir
// de la matriz invocante, una submatriz M en la que se ha eliminado la fila row y la
// columna col especificada. Por otro lado, el método "double signo(int i, int j) const"
// que devuelve (-1)^(i + j).

double signo(int i, int j) {
  return (i + j) % 2 == 0 ? 1 : -1;
}

template <class T>
void cofactor(const int row, const int col, matrix_t<T> &M) {
  assert(m_ == n_);
  M.resize(m_ - 1, n_ - 1);
  int inc_r = 0;
  for (int i = 1; i <= M.get_m(); i++) {
    if (i == row) inc_r = 1;
    int inc_c = 0;
    for (int j; j <= M._get_n(); j++) {
      if (j == col) inc_c = 1;
      M(i, j) = at(i + inc_r, j + inc_c);
    }
  }
}

template <class T>
double determinante(void) {
  assert(m_ == n_);
  if (m_ == 1) return at(1, 1);
  double suma{0.0};
  for (int i = 1; i <= m_; i++) {
    matrix_t<T> M_aux;
    cofactor(i, 1, M_aux);
    suma += at(i, 1) * signo(i, 1) * M_aux.determinante();
  }
  return suma;
}
// EJERCICIO 3. Impleméntese tres métodos constantes para imprimir el contenido de
// una lista simplemente enlazada:

// a) un método recursivo template <class T> void
// sll_t<T>::write_reverse(sll_node_t<T>* node, ostream& os) const que imprima la lista
// en orden inverso.
template <class T>
void sll_t<T>::write_reverse(sll_node_t<T>* node, ostream& os) const {
  write1(head_, os)
}

template <class T>
void sll_t<T>::write1(sll_node<T>* node, ostream& os) {
  if (node != NULL) {
    write1(node->get_next(), os);
    os << node->get_data();
  }
}


// b) un método recursivo template <class T> void sll_t<T>::write_direct(sll_node_t<T>*
// node, ostream& os) const que imprima la lista en orden directo

template <class T>
void sll_t<T>::write_direct(sll_node_t<T>* node, ostream& os) const {
  write2(head_, os);
}

template <class T>
void sll_t<T>::write2(sll_node<T>* node, ostream& os) {
  if (node != NULL) {
    os << node->get_data();
    write2(node->get_next(), os);
  }
}
// c) un método iterativo template <class T> void sll_t<T>::write_reverse(ostream& os)
// const que imprima la lista enlazada en orden inverso.

// Los métodos recursivos 1 y 2 requieren que se implemente también un método
// adicional de llamada.

template <class T> void sll_t<T>::write_reverse(ostream& os) const {
  stack<T> stack;
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    stack.push(aux->get_data());
    aux = aux->get_next();
  }
  
  while (!stack.empty()) {
    os << stack.top();
    stack.pop();
  }
}

// EJERCICIO 4. Desarrolla el método reverse de la clase queue_l_t<T> que modifica sus
// elementos para que estén en orden inverso, es decir, el último elemento de la cola se
// convierte en el primero, el penúltimo en el segundo, y así sucesivamente. Por
// ejemplo, si tenemos la cola Q = [1,2,3,4], la llamada a Q.reverse() hace que quede
// como Q = [4,3,2,1]. Se tendrá muy en cuenta la eficiencia del algoritmo, así como la
// estructura de datos auxiliar utilizada (si fuera necesario).
// void queue_l_t<T>::reverse();

template <class T>
void queue_l_t<T>::reverse() {
  stack_l_t<T> S;

  while (!empty()) {
    S.push(front()); // S = [4,3,2,1]  // El 4 sería el top
    pop();            // Q = []
  }

  while (!S.emtpy()) {
    push(S.top());     // Q = [4,3,2,1] 
    S.pop();          // S = []
  }
}

// EJERCICIO 5. Dados dos conjuntos representados con listas sll_t<int>, desarrollar la
// operación diferencia simétrica △ con la siguiente cabecera:
// void dif_sim(const sll_t<int>& A, const sll_t<int>& B, sll_t<int>& C);
// Por ejemplo, si A = { 11, 5, 7, 3 } y B = { 3, 9, 5, 13 }, C = A △ B = { 13, 9, 7, 11 }.

void dif_sim(const sll_t<int>& A, const sll_t<int>& B, sll_t<int>& C) {
  sll_node_t<int>* aux = A.get_head();
  while (aux != NULL) {
    if (B.search(aux->get_data() == NULL)) {
      C.push_front(new sll_node_t<int>(aux->get_data()));
    }
    aux = aux->get_next();
  }

  aux = B.get_head();
  while (aux != NULL) {
    if (A.search(aux->get_data() == NULL)) {
      C.push_front(new sll_node_t<int>(aux->get_data()));
    }
    aux = aux->get_next();
  }
}

// EJERCICIO 6. Desarrollar el método iterativo especializado de la clase vector_t<int>
// de la búsqueda binaria (BBI):
// int vector_t<int>::BBI(const int x) const;
// que lleva a cabo la búsqueda de un elemento x dentro del vector ordenado invocante.

int vector_t<int>::BBI(const int x) const {
  int i = 0, d = get_size() - 1;
  while (i <= d) {
    int c = (i + d) / 2;
    if (at(c) == x) return c;
    else if (x < at(c)) d = c - 1;
    else if (at(c) < x) i = c + 1; 
  }
  return -1;
}
