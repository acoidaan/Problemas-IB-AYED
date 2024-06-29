#include "../../../AyED/2024/Junio/enunciado.cc"
using namespace std;

template <class T>
void reverse_vector(vector_t<T>& vec, int start = 0) {
  int end = vec.get_size() - 1 - start;
  if (start >= end) return;
  swap(vec.at(start), vec.at(end));
  reverse_vector(vec, start + 1);
}