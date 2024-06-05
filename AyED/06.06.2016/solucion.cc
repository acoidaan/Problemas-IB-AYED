// 1.-  Vectores (4 puntos)

// a) (1 puntos) Impleméntese la función recursiva template <>  vector_t<int>::BBR(int i, int d, int x) const que lleva a cabo la búsqueda recursiva de un elemento x dentro del vector invocante, en los extremos i y d del vector.
int BBR(const vector_t<int>& v, int i, int d, int x) {
  if (i > d) return -1;
  int c = (i + d) / 2;
  if (v.get_v(c) == x) return c;
  else if (x < v.get_v(c)) return BBR(v, i, c - 1, x);
  else if (x > v.get_v(c)) return BBR(v, c + 1, d, x);
}

// b) (1 puntos) Busqueda binario iterativa

int BBI(const vector_t<int>& v, int i, int d, int x) {
  while (i <= d) {
    int c = (i + d) / 2;
    if (v.get_v(c) == x) return c;
    else if (x < v.get_v(c)) d = c - 1;
    else if (x > v.get_v(c)) i = c + 1;
  }
  return -1;
}

// 2.- Matrices (3 puntos) Los algoritmos de los siguiente problemas deben recorrer exactamente la subestructura que se especifica.

// a) (0,5 puntos) Implementar un método para la clase matrix_t<double> que cuente el número de elementos distintos de cero que hay en la submatriz triangular superior, sin contar la diagonal, con la premisa de que la matriz es cuadrada.
int no_zero_TSND(double eps) const {
  int count = 0;
  for (int i = 1; i <= m_ - 1; i++) {
    for (int j = i + 1; j <= n_; j++) {
      if (fabs(v_[pos(i,j)] > eps)) count++;
    }
  }
  return count;
}

// b) (0,5 puntos)  Implementar un método para la clase matrix_t<double> que cuente el número de elementos menores que cero que hay en la submatriz triangular superior, incluyendo la diagonal, con la premisa de que la matriz es cuadrada.

int minor_zero_TSD(double eps) const {
  int count = 0;
  for (int i = 1; i <= m_; i++) {
    for (int j = i; j <= n_; j++) {
      if (v_[pos(i,j)] < -eps) count++;
    }
  }
  return count;
}

// c)  (1 punto)  Implementar un método para la clase matrix_t<int> que devuelva el número de filas que contienen al menos un elemento par.
int even_row(void) const {
  int count = 0;
  for (int i = 1; i <= m_; i++) {
    bool found = false;
    for (int j = 1; (j <= n_) && !found; j++) {
      if (v_[pos(i,j)] % 2 == 0) found = true;
    }
    if (found) count++;
  }
  return count;
}

// d) (1 punto)  Implementar un método para la clase matrix_t<int> que devuelva el número de columnas con más de un elemento distinto de cero.
int cuenta_col_nz(void) const {
  int count = 0;
  for (int j = 1; j <= n_; j++) {
    int lc = 0;
    for (int i = 1; (i <= m_) && (lc < 2); i++) {
      if (v_pos[(i,j)] != 0) lc++;
    }
    if (lc > 1) count++;
  }
  return count;
}

// 3.- Vectores dispersos (3 puntos)

// a) (2 puntos) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_pair_t& b) que devuelve el producto escalar de dos vectores dispersos.
double scalprod(const vector_pair_t& a, const vector_pair_t& b) {
  double scalp = 0.0;
  const int a_sz = a.get_sz();
  const int b_sz = b.get_sz();
  int i = 0, j = 0;

  while ((i < a_sz) && j < b_sz) {
    const int a_inx = a.get_v(i).get_inx();
    const int b_inx = b.get_v(i).get_inx();
    if (a_inx == b_inx) scalp += a.get_v(i++).get_val() * b.get_v(j++).get_val();
   else {
    if (a_inx < b_inx) i++;
    else j++;
  }
  return scalp;
  }
}

// b) (1 punto) Implementar el procedimiento double scalprod(const vector_pair_t& a, const vector_t& b) que devuelve el producto escalar de un vector disperso por otro denso.

double scalprod(const vector_pair_t& a, const vector_t& b) {
  const int a_sz = a.get_sz();
  double scalp = 0.0;

  for (int i = 0; i < a_sz; i++) {
    scalp += a.get_v(i).get_val * b.get_v(get_v(i).get_inx());
  }
  return scalp;
}