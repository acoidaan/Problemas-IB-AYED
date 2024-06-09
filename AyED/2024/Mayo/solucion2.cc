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
  for (int i = v.size(); i >= 0; i--) {
    os << v[i];
  }
  os << endl;
}

void generate(vector<int>& number, int i) {
  if (i < 1) write (number, cout);
  else {
    for (int j{0}; j < 2; j++) {
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

double signo(int i, int j) { // const
  return ((i + j) % 2 == 0) ? 1 : -1;
}

template <class T>
void cofactor(const int row, const int col, matrix_t<T>& M) { // const
  assert (m_ == n_);
  M.resize(m_ - 1, n_ - 1);
  int inc_r = 0;
  for (int i = 1; i <= M.get_m(); i++) {
    if (i == row) inc_r = 1;
    int inc_c = 0;
    for (int j = 1; j <= M.get_n(); j++) {
      M(i, j) = at(i + inc_r, j + inc_c);
    }
  }
}

double determinante(void) { // const
  assert (m_ == n_);
  if (m_ == 1) return at(1, 1);
  double suma{0.0};
  for (int i{1}; i <= m_; i++) {
    matrix_t M_aux;
    cofactor (i, 1, M_aux)
  }
}
// EJERCICIO 3. Impleméntese tres métodos constantes para imprimir el contenido de
// una lista simplemente enlazada:

// a) un método recursivo template <class T> void
// sll_t<T>::write_reverse(sll_node_t<T>* node, ostream& os
sll_t<T>::write_reverse(sll__node_t<T>* node, ostream& os) {
  write1(node, cout);
}

sll_t<T>::write_reverse(sll_node_<T>* node, ostream& os) {
  if (node != NULL) {
    write1(node->get_next(), os);
    os << node->get_data()
  }
}


// b) un método recursivo template <class T> void sll_t<T>::write_direct(sll_node_t<T>*
// node, ostream& os) const que imprima la lista en orden directo

// c) un método iterativo template <class T> void sll_t<T>::write_reverse(ostream& os)
// const que imprima la lista enlazada en orden inverso.

// Los métodos recursivos 1 y 2 requieren que se implemente también un método
// adicional de llamada.

// EJERCICIO 4. Desarrolla el método reverse de la clase queue_l_t<T> que modifica sus
// elementos para que estén en orden inverso, es decir, el último elemento de la cola se
// convierte en el primero, el penúltimo en el segundo, y así sucesivamente. Por
// ejemplo, si tenemos la cola Q = [1,2,3,4], la llamada a Q.reverse() hace que quede
// como Q = [4,3,2,1]. Se tendrá muy en cuenta la eficiencia del algoritmo, así como la
// estructura de datos auxiliar utilizada (si fuera necesario).
// void queue_l_t<T>::reverse();

// EJERCICIO 5. Dados dos conjuntos representados con listas sll_t<int>, desarrollar la
// operación diferencia simétrica △ con la siguiente cabecera:
// void dif_sim(const sll_t<int>& A, const sll_t<int>& B, sll_t<int>& C);
// Por ejemplo, si A = { 11, 5, 7, 3 } y B = { 3, 9, 5, 13 }, C = A △ B = { 13, 9, 7, 11 }.

// EJERCICIO 6. Desarrollar el método iterativo especializado de la clase vector_t<int>
// de la búsqueda binaria (BBI):
// int vector_t<int>::BBI(const int x) const;
// que lleva a cabo la búsqueda de un elemento x dentro del vector ordenado invocante.