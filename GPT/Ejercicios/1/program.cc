#include "../AyED/2024/Junio/enunciado.cc"
using namespace std;

// auxiliar para insertar head
template <class T>
void insert_head(sll_t<T>& list, sll_node_t<T>* new_node) {
  new_node->set_next(list.get_head());
  list.head_ = new_node;
}

template <class T>
void insert_at(sll_t<T>& list, sll_node_t<T>* new_node, int position) {
  if (position == 0) {
    list.insert_head(list, new_node);
    return;
  }

  sll_node_t<T>* current = list.get_head();
  int count = 1;
  while (current != NULL && count < position) {
    current = current->get_next();
    count++;
  }

  if (current == NULL) cout << "fuera de rango" << endl; return;

  new_node->set_next(current->get_next());
  current->set_next(new_node);
}

