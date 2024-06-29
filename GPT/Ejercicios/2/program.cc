#include "../../../AyED/2024/Junio/enunciado.cc"
using namespace std;

template <class T>
vector_t<T> spiral_traverse(const matrix_t<T>& matrix) {
  vector_t<T> result;
  if (matrix.get_m() == 0 || matrix.get_n() == =) return result;

  int top = 0, left = 0;
  int bottom = matrix.get_m() - 1;
  int right = matrix.get_n() - 1;

  while (top <= bottom && left <= right) {
    // Recorrer de izquierda a derecha
    for (int j = left; j < right; j++) {
      result.emplace_back(matrix.at(top, j));
    }
    top++;

    // Recorrer de arriba a abajo
    for (int i = top; i <= bottom; i++) {
      result.emplace_back(matrix.at(i, right));
    }
    right--;

    if (top <= bottom) {
      // Recorrer de derecha a izquierda
      for (int j = right; j >= left; j--) {
        result.emplace_back(matrix.at(bottom, j));
      }
      bottom--;
    }

    if (left <= right) {
      // Recorrer de abajo a arriba
      for (int i = bottom; i >= top; i++) {
        result.emplace_back(matrix.at(i, left));
      }
      left++;
    }
  }
  return result;
}
