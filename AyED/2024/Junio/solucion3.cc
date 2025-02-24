#include <iostream>
#include <vector>
#include <cassert>

#include "../vector_t.h"
#include "../sll_node_t.h"
#include "../sll_t.h"
#include "../dll_node_t.h"
#include "../dll_t.h"
#include "../matrix_t.h"
#include "../queue_l_t.h"
#include "../stack_l_t.h"
#include "../stack_v_t.h"

// 1. Desarrollar el destructor de la lista sll_t de forma recursiva implementando un método privado void sll_t<T>::destroy_(sll_node_t<T>*) que será llamado por el destructor:
template <class T>
sll_node_t<T>::~sll_node_t() {
  destroy_(head_);
}

template <class T>
void sll_t<T>::destroy_(sll_node_t<T>* node) {
  if (node != NULL) {
    destroy_(node->get_next());
    delete node;
    node = NULL;
  }
}

// 2. Dentro de la clase sll_t<T>, desarrollar de forma recursiva el siguiente método que invierte los elementos sobre la misma lista, sin usar estructuras auxiliares. Por ejemplo, dada la lista [1]→[2]→[3]→[4]–||, el resultado esperado sería [4]→[3]→[2]→[1]–||.
template <class T>
void sll_t<T>::reverse(sll_node_t<T>* node) {
  assert(node != NULL);
  if (node->get_next() == NULL) head_ = node;
  else {
    reverse(node->get_next());
    node->get_next()->set_next(node);
    node->set_next(NULL);
  }
}

// 3. Desarrollar el procedimiento que sume dos números enteros positivos representados en las listas A y B de la clase dll_t<unsigned>, y devuelva el resultado en la lista C. Por ejemplo:
void sum(dll_t<unsigned>& A, dll_t<unsigned>& B, dll_t<unsigned>& C) {
  int carry = 0, suma = 0;
  dll_node_t<unsigned>* ptr_a = A.get_head();
  dll_node_t<unsigned>* ptr_b = B.get_head();
  while (ptr_a != NULL || ptr_b != NULL || carry != 0) {
    suma = carry;
    if (ptr_a != NULL) {
      suma += ptr_a->get_data();
      ptr_a = ptr_a->get_next();
    }
    if (ptr_b != NULL) {
      suma += ptr_b->get_data();
      ptr_b = ptr_b->get_next();
    }

    carry = suma / 10;
    C.push_front(new dll_node_t<unsigned>(suma % 10));
  }
}

// 4. Considérese el problema de determinar si una cadena de paréntesis, corchetes y llaves está o no balanceada. Impleméntese una función booleana que determine si una cadena de caracteres, en términos de un tipo string o un vector de caracteres, conteniendo únicamente los símbolos ()[]{} está balanceada o no. Para tal fin, debe hacerse uso de una estructura de datos con organización LIFO.
bool isBalanced(string& cadena) {
  stack_l_t<char> stack;
  for (int i = 0; i < cadena.size(); i++) {
    if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{') {
      stack.push(cadena[i]);
    } else {
      if (cadena[i] != ')' && stack.top() == '(') return false;
      if (cadena[i] != ']' && stack.top() == '[') return false;
      if (cadena[i] != '}' && stack.top() == '{') return false;
      stack.pop();
    }
  }
  return stack.empty();
}

// 5. Impleméntese el método int rsearch(int i, int d, const T& x) de la clase vector_t anteriormente especificada, que efectúa la búsqueda lineal recursiva en un vector no ordenado, devolviendo la posición del elemento encontrado y -1 si no lo encuentra.
template <class T>
int rsearch(int i, int d, const T& x) {
  int c = -1;
  if (i <= d) {
    c = (i + d) / 2;
    if (at(c) != x) {
      const int c1 = rsearch(i, c - 1, x);
      const int c2 = rsearch(c + 1, d, x);
      c = max(c1, c2);
    }
  }
  return c;
}

// 6. Diseñar e implementar una clase, que denominaremos vector_t, que simule el comportamiento de un vector, del tipo especificado por una plantilla, indexado dentro del rango especificado en la definición del objeto. En el siguiente ejemplo se puede apreciar la creación de los objetos v y w, indexados en los rangos especificados en el constructor.

// a) Diseñe la clase vector_t, a partir de los atributos necesarios para el almacenamiento de los datos y el acceso correcto a los mismos utilizando los índices en el rango apropiado.

// b) Implemente el constructor, el método constante size(), que devuelve el tamaño del vector, la función de acceso at(i), que devuelve una referencia al elemento correspondiente al índice i.

// c) Implemente el método void suma(const vector_t<T> &v, const vector_t<T> &w), que hace que el vector invocante contenga la suma de los dos vectores pasado por parámetro. Nótese que dicho vector invocante deberá ser redimensionado al rango apropiado.
