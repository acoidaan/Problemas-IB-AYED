#include <iostream>
#include "enunciado.cc"
using namespace std;

// 1
template <class T>
sll_t<T>::~sll_t(void) {
  destroy(get_head());
}

template <class T>
void sll_t<T>::destroy_(sll_node_t<T>* p) {
  if (p != NULL) {
    destroy(p->get_next())
    delete p;
    p = NULL;
  }
}

// 2
template <class T>
void sll_t<T>::reverse(sll_node_t<T>* p) {
  assert (p != NULL);
  if (p->get_next() == NULL) head_ = p;
  else {
    reverse(p->get_next());
    p->get_next()->set_next(p);
    p->set_next(NULL);
  }
}

// 3
void sum(dll_t<unsigned>& A, dll_t<unsigned> B, dll_t<unsigned>& C) {
  assert(!A.empty() && !B.empty());
  dll_node_t<unsigned>* ptr_a = A.get_tail();
  dll_node_t<unsigned>* ptr_b = B.get_tail();
  unsigned carry = 0;
  while (ptr_a != NULL || ptr_b != NULL) {
    int vA = 0, vB = 0;
    if (ptr_a) {
      vA = ptr_a->get_data();
      ptr_a = ptr_a->get_prev();
    }
    if (ptr_b) {
      vB = ptr_b->get_data();
      ptr_b = ptr_b->get_prev();
    }
    unsigned s = vA + vB + carry;
    if (s >= 10) {
      carry = 1;
      s -= 10;
    } else carry = 0;
    C.push_front(new dll_node_t<unsigned>(s));
  }
  if (carry == 1) C.push_front(new dll_node_t<unsigned>(1));
}

// 4
bool IsBalanced(const string s) {
  stack_v_t<char> p;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') p.push(s[i]);
    else {
      if (p.empty()) return false;
      if (s[i] == ')' && p.top() != '(') return false;
      if (s[i] == ']' && p.top() != '[') return false;
      if (s[i] == '}' && p.top() != '{') return false;
      p.pop();
    }
  }
  return p.empty();
}

// 5

int rsearch(const int* v, int i, int d, int x) {
  int c = -1;
  if (i <= d) {
    c = (i + d) / 2;
    if (v[c] != x) {
      const int c1 = rsearch(v, i, c - 1, x);
      const int c2 = rsearch(v, c + 1, d, x);
      c = max(c1, c2);
    }
  }
  return c;
}

// 6
template <class T>
class vector_t {
 private:
  T* v_;
  int l_, r_;
 
 public:
  vector_t(int l, int r) : v_(NULL), l_(l), r_(r) {
    v_ = new T[size()];
  }
  int size(void) const { return r_ - l_ + 1; }
  T &at(int pos) { return v_[pos - l_]; }

  void suma(const vector_t<T>& v, const vector_t<T>& w) {
    l_ = (v.l_ < w.l_) ? v.l_ : w.l_;
    r_ = (v.r_ > w.r_) ? v.r_ : w.r_;

    resize();
    init(0);

    for (int i = v.l_; i <= v.r_; i++) {
      at(i) = v.at(i);
    }
    for (int i = w.l_; i <= w.r_; i++) {
      at(i) += w.at(i);
    }
  }
};