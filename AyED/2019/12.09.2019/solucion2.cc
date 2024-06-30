#include "../../../AyED/2024/Junio/enunciado.cc"
using namespace std;
// 1. Desarrollar los siguientes algoritmos de la clase dll_t<T>:

// (a) (1.0) Inserción por el final:
template <class T>
void dll_t<T>::insert_tail(dll_node_t<T>* node) {
  if (empty()) {
    head_ = node;
    tail_ = head_;
  } else {
    tail_->set_next(node);
    node->set_prev(tail_);
    tail_ = node;
  }
  sz_++;
}

// (b) (1.0) Eliminación de un nodo determinado:
template <class T>
dll_node_t<T>* dll_t<T>::erase(dll_node_t<T>* node) {
  assert(node != NULL);
  if (node->get_prev() != NULL) {
    node->get_prev()->set_next(node->get_next());
  } else {
    head_ = node->get_next();
  }

  if (node->get_next() != NULL) {
    node->get_next()->set_prev(node->get_prev());
  } else {
    tail_ = node->get_prev();
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
  for (int i = 0; i < s.get_size(); i++) {
    if (s[i] != s[s.get_size() - 1 - i]) return false;
  }
  return true;
}

// (b) (1.5) Desarrollar un algoritmo recursivo que retorne true si dada una frase dentro de un vector_t<char> es palíndroma o no, y con la siguiente cabecera:
bool is_palindrome_r(const vector_t<char>& s, int i, int d) {
  if (i >= d) return true;
  return (s[i] == s[d] && is_palindrome_r(s, i + 1, d - 1));
}