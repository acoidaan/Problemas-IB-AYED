// 1. Considérese el tipo de datos matrix_t definido anteriormente. Considérese también que el objeto invocado es una matriz cuadrada de elementos tipo double. Impleméntese cuatro métodos que sumen los elementos de las siguientes submatrices, recorriendo únicamente la submatriz especificada.

// (a) (0.5) Submatriz triangular superior incluyendo la diagonal principal.

#include <iostream>
double TSD(void) const {
  double suma = 0.0;
  for (int i = 1; i <= m_; i++) {
    for (int j = 1; j <= m_: j++) {
      suma += at(i, j);
    }
  }
  return suma;
}

// (b) (0.5) Submatriz triangular superior sin incluir la diagonal principal 
double TSND(void) const {
  double suma = 0.0;
  for (int i = 1; i <= m_ - 1; i++) {
    for (int j = i + 1; j <= n_; j++) {
      suma += at(i, j);
    }
  }
  return suma;
}

// (c) (0.5) Submatriz triangular inferior incluyendo la diagonal principal.

double TID(void) const {
  double suma = 0.0;
  for (int i = 1; i <= m_; i++) {
    for (j = 1; j <= i; j++) {
      suma += at(i, j);
    }
  }
  return suma;
}

// d) (0.5) Submatriz triangular inferior sin incluir la diagonal principal.

double TIND(void) const {
  double suma = 0.0;
  for (int i = 2; i <= m_; i++) {
    for (int j = 1; j <= i - 1; j++) {
      suma += at(i, j);
    }
  }
  return suma;
}

// 3. (1.0) Considérese un vector de números enteros v, definido por los extremos i (izquierdo) y d (derecho). Como premisa sabemos que los elementos de v están ordenados en orden no decreciente. Se desea obtener la posición de una ocurrencia del valor x dentro del vector. Impleméntese una función que efectúe una búsqueda binaria recursiva en un vector ordenado, y que devuelva la posición de una ocurrencia del elemento buscado, o -1 en caso de no encontrarse.

int bsearch(const int* v, int i, int d, int x) {
  int c = -1;
  if (i <= d) {
    c = (i + d) / 2;
    if (v[c] != x) {
      if (x < v[c]) c = bsearch(v, i, c - 1, x);
    } else {
      c = bsearch(v, c + 1, d, x);
    }
  }
  return c;
}

// 4. (1.0) Considérese la clase sll_t. Impleméntese un procedimiento recursivo que imprima los elementos de la lista simplemente enlazada en orden inverso. Con este fin, el método debe recibir como parámetro un puntero a un nodo, y un stream de salida. Este método debe comprobar si el nodo es nulo o no. En caso de que fuera nulo debe retornar, si no es nulo, debe llamarse nuevamente con en nodo siguiente, e imprimir el contenido del nodo.

void writeReverse(sll_node_t* node, ostream& os) const {
  write1(head_, os);
}

void write1(sll_node_t* node, ostream& os) const {
  if (node != NULL) {
    write1(node->get_next(), os);
    os << node->get_data();
  }
}

// 5. Sobre la clase sll_t, desarrollar los siguientes apartados:
// (a) (0.5) Implementar el método void sll_t<T>::insert_head(sll_node_t<T>*)
template <class T>
void sll_t<T>::insert_head(sll_node_t<T>* n) {
  n->set_next(head_);
  head_ = n;
}

// (b) (0.5) Implementar el método void sll_t<T>::insert_tail(sll_node_t<T>*)

template <class T>
void sll_t<T>::insert_tail(sll_node_t<T>* n) {
  if (empty()) insert_head(n);
  else {
    sll_node_t<T>* aux = head_;
    while (aux->get_next() != NULL) {
      aux = aux->get_next();
    }
    insert_after(aux, n);
  }
}

// (c) (0.5) Implementar el método especializado sll_node_t<int>* sll_t<int>::find(const int v) 
// que busca un valor dentro de la lista, devolviendo el puntero del nodo que lo contiene o NULL si no lo encuentra.

template <class T>
sll_node_t<int>* sll_t<int>::find(const int v) {
  assert(!empty());
  sll_node_t<int> *ptr = head();
  while (ptr != NULL && ptr->get_data() != v) {
    ptr = ptr->get_next();
  }
  return ptr;
};

// 6. (1.0) Implementar la siguiente función recursiva del algoritmo de Euclides, que calcula el máximo común divisor (mcd) de dos enteros:

int mcd(int x, int y) {
  if (y == 0) return x;
  return mcd(y, x % y);
};

// 7. (1.0) Implementar el procedimiento:
// void sll_intersect(sll_t<int>& A, sll_t<int>& B, sll_t<int>& C)
// que realiza la intersección (tipo conjunto) de dos listas no ordenadas A y B con elementos no repetidos,
// y devuelve el resultado en la lista C. Puede usarse la funcionalidad desarrollada en los apartados 5(b) y 5(c). Por ejemplo, si A={2,1,4,3} y B={1,5,3,6}, el resultado sería C={1, 3}.

void sll_intersect(sll_t<int>& A, sll_t<int>& B, sll_t<int>& C) {
  sll_node_t<int>* ptr = A.head();
  while (ptr != NULL) {
    if (B.find(ptr->get_data()) != NULL) {
      C.insert_tail(new sll_node_t<int>(ptr->get_data()));
    }
    ptr = ptr->get_next();
  }
}

// 8. (1.5) Implementar el procedimiento void sll_union(sll_t<int>& A, sll_t<int>& B, sll_t<int>& C)
// que realiza la unión (tipo conjunto) de dos listas no ordenadas A y B con elementos no repetidos, y devuelve el resultado en la lista C. Para ello, puede usarse la funcionalidad desarrollada en el apartado 5(b) y 5(c). Por ejemplo, si A={2,1,4,3} y B={1,5,3,6}, el resultado sería C={2,4,1,5,3,6}.

template <class T>
void sll_union(sll_t<int>& A, sll_t<int>& B, sll_t<int>& C) {
  dll_node_t<int> *ptr = A.head();
  while (ptr != NULL) {
    if (B.find(ptr->get_data()) == NULL)) {
    C.insert_tail(new dll_node_t<int>(ptr->get_data()));
    }
  ptr = ptr->get_next();
  }
  ptr = B.head();
  while (ptr != NULL) {
    C.insert_tail(new dll_node_t<int>(ptr->get_data()));
    ptr = ptr->get_next();
  }
}