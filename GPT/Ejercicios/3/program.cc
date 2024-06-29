#include "../../../AyED/2024/Junio/enunciado.cc"
using namespace std;

// Mezclar de menor a mayor 
template <class T>
dll_t<T> merge_dll(const dll_t<T>& list1, const dll_t<T>& list2) {
  dll_node_t<T>* ptr1 = list1.get_head();
  dll_node_t<T>* ptr2 = list2.get_head();

  dll_t<T> list3;

  while (ptr1 != NULL && ptr2 != NULL) {
    if (ptr1->get_data() <= ptr2->get_data()) {
      list3.push_back(new dll_node_t<T>(ptr1->get_data()));
      ptr1 = ptr1->get_next();
    } else if (ptr1->get_data() > ptr2->get_data()) {
      list3.push_back(new dll_node_t<T>(ptr2->get_data()));
      ptr2 = ptr2->get_next();
    }

  }
  while (ptr1 != NULL) {
    list3.push_back(new dll_node_t<T>(ptr1->get_data()));
    ptr1 = ptr1->get_next();
  }

  while (ptr2 != NULL) {
    list3.push_back(new dll_node_t<T>(ptr2->get_data()));
    ptr2 = ptr2->get_next();
  }
  return list3;
}