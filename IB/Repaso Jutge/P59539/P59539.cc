// https://jutge.org/problems/P59539_en
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  int n;
  cin >> n;
  double sum{0.0};
  for (int i = 1; i <= n; i++) {
    sum += 1.0 / i;
  }
  cout << fixed << setprecision(4) << sum << endl;
}