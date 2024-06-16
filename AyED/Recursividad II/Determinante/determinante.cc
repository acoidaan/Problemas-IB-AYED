#include <iostream>
#include <fstream>
#include "../matrix_t.hpp"
#include "../vector_t.hpp"
using namespace std;

double Determinante(const matrix_t<int>& mat) {
  if (mat.get_m() == 1) return mat(1, 1);
  double sum{0.0};
  matrix_t<int> submat(mat.get_m() - 1, mat.get_n() - 1);
  for (int col = 1; col <= mat.get_m(); col++) {
    for (int i = 1; i <= submat.get_m(); i++) {
      for (int j = 1; j <= submat.get_n(); j++) {
        submat(i, j) = mat(i + 1, j < col ? j : j + 1);
      }
    }
    sum = sum + (col % 2 == 1 ? 1 : -1) * mat(1, col) * Determinante(submat);
  }
  return sum;
}

int main(int argc, char* argv[]) {
  matrix_t<int> mat;
  cin >> mat;
  cout << "Se muestra la matriz: " << endl;
  cout << mat << endl;
  cout << "Determinante: " << Determinante(mat) << endl;
  return 0;
}