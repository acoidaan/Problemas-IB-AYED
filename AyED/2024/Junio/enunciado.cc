#include <iostream>
#include <vector>
#include <cassert>

#include "../vector_t.h"
#include "../sll_node_t.h"
#include "../sll_t.h"
#include "../vector_t.h"
#include "../matrix_t.h"
#include "../queue_l_t.h"
#include "../stack_l_t.h"
#include "../stack_v_t.h"

// 1. Destructor recursivo sll
// 2. Dar la vuelta a una sll de manera recursiva
// 3. Un método con 3 listas dll que hiciera una suma de toda la vida con acarreo
// 4. Búsqueda binaria recursiva/iterativa (no me acuerdo cual de las dos) pero la lista no está ordenada
// 5. Ver si una cadena de ([{}]) está balanceada con LIFO
// 6. Diseñar clase vector dual

// 1
template <class T>
sll_t<T>::~sll_t(void) {
  destructor(head_);
}

template <class T>
void sll_t<T>::destroy(sll_node_t<T>* node) {
  if (node != NULL) {
    destroy(node->get_next());
    delete node;
  }
}

// 2
template <class T>
void sll_t<T>::reverse(void) {
  reverse_helper(head_, NULL);
}

template <class T>
void sll_t<T>::reverse_helper(sll_node_t<T>* current, sll_node_t<T>* prev) {
  if (current == NULL) {
    head_ = prev;
    return;
  } else {
    reverse_helper(current->get_next(), current);
    current->set_next(prev);
  }
}

// 3
template <class T>
dll_t<int> dll_t<T>::suma(dll_t<int>& A, dll_t<int>& B) {
  int carry = 0;
  dll_node_t<int>* nodo_a = A.get_tail();
  dll_node_t<int>* nodo_b = B.get_tail();
  dll_t<int> result;

  while (nodo_a != NULL || nodo_b != NULL || carry != 0) {
    int sum = carry;
    if (nodo_a != NULL) {
      sum += nodo_a->get_data();
      nodo_a = nodo_a->get_next();
    }

    if (nodo_b != NULL) {
      sum += nodo_b->get_data();
      nodo_b = nodo_b->get_next();
    }

    carry = sum / 10;
    result.push_front(new dll_node_t<int>(sum % 10));
  }
  return result;
}


// 4 Esperando a las soluciones del profe

// 5
bool isBalanced(const string& cadena) {
  stack_v_t<char> pila;
  for (char c : cadena) {
    if (c == '(' || c == '[' || c == '{') {
      pila.push(c);
    } else {
      if (pila.empty()) return false;
      char top = pila.top();
      if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
        pila.pop();
      } else return false; 
    }
  }
  return pila.empty();
}

// 6
template <class T>
class dual_vector {
 private:
  T *v_;
  int a_;
  int b_;
 public:
  dual_vector(const int a, const int b);
  dual_vector(size_t sz);
  ~dual_vector(void);
  size_t get_sz(void) const;
  T& at(int i);
  const T& at(int i) const;
};

template <class T>
dual_vector<T>::dual_vector(const int a, const int b) : v_(NULL), a_(a), b_(b) {
  v_ = new T[set_sz()];
}

template <class T>
dual_vector<T>::dual_vector(size_t sz) : v_(NULL), a_(a), b_(sz - 1) {
  v_ = new T[get_size()];
}

template <class T>
size_t dual_vector<T>::get_sz(void) const {
  return b = -a_ - 1;
}

template <class T>
T& dual_vector<T>::at(int i) {
  return v_[i - a];
}

template <class T>
dual_vector<T>::~dual_vector(void) {
  if (v_ != NULL) {
    delete[] v_;
  }
}
