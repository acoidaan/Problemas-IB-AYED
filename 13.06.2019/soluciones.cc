// 1. Dada la clase sll_t, desarrollar los siguientes métodos relacionados con el destructor:
// sll_t<T>::~sll_t(void)
// (a) (0.5) Destructor iterativo.
sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T> aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

// (b) (1.0) Destructor recursivo.
// Pista: como un destructor no se puede llamar a sí mismo, puedes hacer uso de un método auxiliar.

sll_t<T>::~sll_t(void) {
  destroy(head_);
}

void sll_t<T>::destroy(sll_node_t<T>* n) {
  if (n != NULL) {
    destroy(n->get_next());
    delete n;
  }
}

// 2. Dado el tipo de datos conjunto_t (definido como un unsigned short) que almacena los elementos de un conjunto U={0 ,..., 15} con |U| = 16, en forma de bits, se pide:
// (a) (0.5) Desarrollar la función
// void remove(conjunto_t& C, unsigned i)
// que elimina el elemento i del conjunto C.

void remove(conjunto_t& c, unsigned i) {
  conjunto_t uno 0x1;
  uno <<= i;
  C &= ~uno;
}

// (b) (1.0) Desarrollar la función XOR (△):
// conjunto_t XOR(conjunto_t A, conjunto_t B);
// que recibe como parámetros dos conjuntos, y devuelve la operación XOR. Por ejemplo, sea A = { 5, 7, 11 } y B = { 1, 3, 5 }, entonces C = A △ B = { 1, 3, 7, 11 }
conjunto_t XOR(conjunto_t A, conjunto_t B) {
  return (A | B) & ~(A & B);
}

// 3. Dada la clase vector_t<double>, implementar los siguientes apartados.
// (a) (0.5) Producto escalar iterativo entre un vector invocante y otro pasado por parámetro, siempre y cuando los dos vectores sean del mismo tamaño.
// double vector_t<double>::scal_prod(const vector_t<double>& b)
double vector_t<double>::scal_prod(const vector_t<double>& b) {
  assert(size() == b.size());
  double s = 0.0;
  for (int i = 0; i < size(); i++) {
    s += at(i) * b[i];
  }
  return s;
}

// (b) (1.5) Producto escalar recursivo entre un vector invocante y otro pasado por parámetro, siempre y cuando los dos vectores sean del mismo tamaño.
// double vector_t<double>::scal_prod_r(const vector_t<double>& b, int i = 0)
// Pista: mirar el parámetro i que por defecto es 0.
double vector_t<double>::scal_prod_r(const vector_t<double>& b, int i = 0) {
  assert(size() == b.size());
  if (i == size()) return 0;
  return at(i) * b[i] + scal_prod_r(b, i + 1);
}

// 4. (1.0) Considérese un vector de números enteros v, definido por los extremos i (izquierdo) y d (derecho). Los elementos del vector no siguen ningún orden. Se desea obtener la posición de una ocurrencia del valor x dentro del vector. Impleméntese una función que efectúe una búsqueda binaria recursiva, y que devuelva la posición de una ocurrencia del elemento buscado, o -1 en caso de no encontrarse.

int rsearch(const int* v, int i, int d, int x) {
  int c = -1;
  if (i <= d) {
    c = (i + d) / 2;
    if (v[c] != x) {
    if (v[c] < x) c = rsearch(v, i, c - 1, x);
    else c = rsearch(v, c + 1, d, x);
    }
  }
  return c;
}

// 5. (1.5) Considérese la clase sll_t. Impleméntese un procedimiento no recursivo que imprima los elementos de la lista simplemente enlazada en enteros, cuyos valores sean par, en orden inverso. Con este fin se utilizará una estructura de tipo pila en la que se almacenarán los datos de la lista enlazadas.

template <class T>
void sll_t<T>::writeReverseStack(ostream& os) const {
  stack<T> stack;
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    if(aux->get_data() % 2 == 0) {
      stack.push(aux->get_data());
    }
    aux = aux->get_next();
  }

  while (!stack.empty()) {
    os << stack.top();
    stack.pop();
  }
};
