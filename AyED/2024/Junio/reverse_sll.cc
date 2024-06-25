#include "enunciado.cc"
using namespace std;
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

template <class T>
void sll_t<T>::reverse(void) {
  reverse_helper(head_, NULL);
}

// HEAD->[1]->[2]->[3]->[4]->NULL
// NULL<-[1]<-[2]<-[3]<-[4]<-HEAD