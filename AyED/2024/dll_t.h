// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node_t.h"

// Clase para almacenar una lista doblemente enlazada
template <class T> class dll_t {
 public:
  // constructor
  dll_t(void) : head_(NULL), tail_(NULL), sz_(0) {}

  // destructor
  ~dll_t(void); 

  // getters
  dll_node_t<T>* get_tail(void) const { return tail_; }
  dll_node_t<T>* get_head(void) const { return head_; }
  int get_size(void) const { return sz_; }

  bool empty(void) const;

  // operaciones
  void push_back(dll_node_t<T>*);
  void push_front(dll_node_t<T>*);

  dll_node_t<T>* pop_back(void);
  dll_node_t<T>* pop_front(void);

  // Junio 2024
  dll_t<int> suma(dll_t<int>& A, dll_t<int>& B);

  dll_node_t<T>* erase(dll_node_t<T>* node);

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

  dll_node_t<int>* find(const int v);

  // Mis cosas
  void insert_tail(dll_node_t<T>* node);

 private:
  dll_node_t<T>* head_;
  dll_node_t<T>* tail_;
  int            sz_;
};


// destructor
template <class T> dll_t<T>::~dll_t(void) {
  while (head_ != NULL) {
    dll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
  sz_ = 0;
  tail_ = NULL;
}

// Comprobar si lista vacía
template <class T> bool dll_t<T>::empty(void) const {
  if (head_ == NULL) {
    assert(tail_ == NULL);
    assert(sz_ == 0);
    return true;
  } else
    return false;
}

// operaciones
template <class T> void dll_t<T>::push_front(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    head_->set_prev(nodo);
    nodo->set_next(head_);
    head_ = nodo;
  }
  sz_++;
}

template <class T> void dll_t<T>::push_back(dll_node_t<T>* nodo) {
  assert(nodo != NULL);

  if (empty()) {
    head_ = nodo;
    tail_ = head_;
  } else {
    tail_->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_back(void) {
  assert(!empty());

  dll_node_t<T>* aux = tail_;
  tail_ = tail_->get_prev();
  if (tail_ != NULL)
    tail_->set_next(NULL);
  else
    head_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

template <class T> dll_node_t<T>* dll_t<T>::pop_front(void) {
  assert(!empty());

  dll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  if (head_ != NULL)
    head_->set_prev(NULL);
  else
    tail_ = NULL;
  sz_--;
  aux->set_next(NULL);
  aux->set_prev(NULL);
  return aux;
}

// template <class T> dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* nodo) {
//   assert(nodo != NULL);

//   if (nodo->get_prev() != NULL)
//     nodo->get_prev()->set_next(nodo->get_next());
//   else
//     head_ = nodo->get_next();
//   if (nodo->get_next() != NULL)
//     nodo->get_next()->set_prev(nodo->get_prev());
//   else
//     tail_ = nodo->get_prev();
//   sz_--;
//   nodo->set_prev(NULL);
//   nodo->set_next(NULL);
//   return nodo;
// }

// E/S
template <class T> std::ostream& dll_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

// Junio 2024
dll_t<int> dll_t<int>::suma(dll_t<int>& A, dll_t<int>& B) {
  dll_t<int> result;
  dll_node_t<int>* nodo_A = A.get_tail();
  dll_node_t<int>* nodo_B = B.get_tail();
  int carry = 0;

  while (nodo_A != NULL || nodo_B != NULL || carry != 0) {
    int sum = carry;
    if (nodo_A != NULL) {
      sum += nodo_A->get_data();
      nodo_A = nodo_A->get_next();
    }

    if (nodo_B != NULL) {
      sum += nodo_B->get_data();
      nodo_B = nodo_B->get_next();
    }

    carry = sum / 10; // Ajustar el carry
    dll_node_t<int>* aux = new dll_node_t<int>(sum % 10);
    result.push_front(aux);
  }
  return result;
}

#endif  // DLLT_H_
