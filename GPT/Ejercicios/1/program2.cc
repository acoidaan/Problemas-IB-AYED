#include "../../../AyED/2024/Junio/enunciado.cc"
using namespace std;

// aux para head
template <class T>
void insert_head(sll_t<T>& list, sll_node_t<T>* node) {
  node->set_next(list.get_head());
  list.head_ = node;
}

template <class T>
void insert_at(sll_t<T>& list, sll_node_t<T>* new_node, int position) {
  if (position == 0) {
    insert_head(list, new_node);
    return;
  }

  int count = 1;
  sll_node_t<T>* aux = list.get_head();
  while (aux != NULL && count < position){
    aux = aux->get_next();
    count++;
  }
  if (aux == NULL) {
    cout << "fuera de rango" << endl;
    return;
  }
  new_node->set_next(aux->get_next());
  aux->set_next(new_node);
}