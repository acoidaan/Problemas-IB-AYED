// https://jutge.org/problems/P39225_en
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num;
  cin >> num;
  vector<int> number_vector;
  int numbers;
  while (cin >> numbers && numbers >= 0) {
    number_vector.emplace_back(numbers);
  }
  cout << "At the position " << num << " there is a(n) " <<  number_vector[num - 1] << '.' << endl;
}