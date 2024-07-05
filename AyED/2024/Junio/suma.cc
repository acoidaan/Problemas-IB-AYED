#include "enunciado.cc"
using namespace std;

// dll_t<int> suma(dll_t<int>& A, dll_t<int>& B)
dll_t<int> dll_t<int>::suma(dll_t<int>& A, dll_t<int>& B) {
  int carry = 0;
  dll_t<int> result;
  dll_node_t<int>* nodo_A = A.get_tail();
  dll_node_t<int>* nodo_B = B.get_tail();

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
    
  carry = sum / 10;
  result.push_front(new dll_node_t<int>(carry % 10));
  }
  return result;
}