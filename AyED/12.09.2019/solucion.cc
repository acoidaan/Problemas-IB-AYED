#include <iostream>
using namespace std;
// 1. Desarrollar los siguientes algoritmos de la clase dll_t<T>:

// (a) (1.0) Inserción por el final:

void dll_t<T>::insert_tail(dll_node_t<T>* nodo) {
  assert(nodo != NULL);
  if (empty()) {
    head_ = nodo;
    tail_ = head;
  } else {
    tail->set_next(nodo);
    nodo->set_prev(tail_);
    tail_ = nodo;
  }
  sz_++;
}

// (b) (1.0) Eliminación de un nodo determinado:

void dll_t<T>::remove(dll_node_t<T>* n) {
  assert (n != NULL) {
    if (n->get_prev() != NULL) {
      n->get_prev()->set_next(n->get_next());
    } else {
      head_ = n->get_next();
      head_ = set_prev(NULL);
    }
    if (n->get_next() != NULL) {
      n->get_next()->set_prev(n->get_prev());
    } else {
      tail_ = n->get_prev();
      tail_ = set_prev(NULL);
    }
    delete n;
    sz_--;
  }
}

// 2. Dada la siguiente función recursiva:
// (a) (0.5) Desarrollar el algoritmo recursivo con la siguiente cabecera:

int potencia(int base, unsigned int expo) {
  if (expo == 0) return 1;
  else return base * potencia(base, expo - 1);
}

// 3. Un palíndromo es una palabra o frase que se lee igual de izquierda a derecha que de derecha a izquierda. Por ejemplo: "Dábale arroz a la zorra el abad". Si la frase se guarda en un objeto de la clase vector_t<char> normalizada a mayúsculas, sin acentos y sin espacios (por ejemplo, “DABALEARROZALAZORRAELABAD”) se pide:

// (a) (0.5) Desarrollar un algoritmo iterativo que retorne true si dada una frase dentro de un vector_t<char> es palíndroma o no, y con la siguiente cabecera:

bool is_palindrome(const vector_t<char>& s) {
  for (int i = 0; i <= s.size() / 2; i++) {
    if (s[i] != (s.size() - 1 - i)) return false;
  }
  return true;
}

// (b) (1.5) Desarrollar un algoritmo recursivo que retorne true si dada una frase dentro de un vector_t<char> es palíndroma o no, y con la siguiente cabecera:

bool is_palindrome_r(const vector_t<char>& s, int i, int d) {
  if (i >= d) return true;
  return (s[i] == s[d] && is_palindrome_r(s, i + 1, d - 1));
}

