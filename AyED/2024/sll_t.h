// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T> class sll_t {
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);
  void destroy_(sll_node_t<T>* p);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };
  
  bool empty(void) const;

  void write_reverse(sll_node_t<T>* node, ostream& os) const;

  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);

  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);

  sll_node_t<T>* search(const T&) const;

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;
  // Junio 2024
  // para destructor recursivo 
  void destroy(sll_node_t<T>* node);
  // invertir sll sin estructura auxiliar y recursiva
  void reverse(sll_node_t<T>* p);
  void erase_evens(void)


 private:
  sll_node_t<T>* head_;
};


// destructor
// template <class T> sll_t<T>::~sll_t(void) {
//   while (!empty()) {
//     sll_node_t<T>* aux = head_;
//     head_ = head_->get_next();
//     delete aux;
//   }
// }

// destructor recursivo
template <class T> sll_t<T>::~sll_t(void) {
  destroy(head_);
}

// auxiliar para ardestructor recursivo 
template <class T> void sll_t<T>::destroy(sll_node_t<T>* node) {
  if (node != NULL) {
    destroy(node->get_next());
    delete node;
  }
}
 
template <class T> sll_t<T>::~sll_t(void) {
  if (this == NULL) return;
  else ~sll_t(this->get_next()) {
    delete this;
  }
}

// Comprobar si lista vacía
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev,
					       sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

// E/S
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

#endif  // SLLT_H_
