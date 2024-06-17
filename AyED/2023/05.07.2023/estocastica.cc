#include <iostream>
using namespace std;

template<>
bool matrix_t<int>::is_estocastica(void){
  int sum;
  bool estocastica = true;
  for (int i = 1; i <= m_; i++) {
    for (int j = 1; j <= n_; j++) {
      if (M[i][j] < 0) estocastica = false;
    }
  }
  if (estocastica) {
    for (int i = 1; i <= m_; i++) {
      sum = 0;
      for (int j = 1; j <= n_; j++) {
        sum += M[j][i];
      }
      if (sum != 1) estocastica = false;
    }
  }
  return estocastica;
}