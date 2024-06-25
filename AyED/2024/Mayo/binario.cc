#include <iostream>
#include <vector>
using namespace std;

#define N_DIGITS 4

void write(vector<int>& v, ostream& os) {
  for (int i = 0; i <= v.size() - 1; i++) {
    os << v[i];
  }
  os << endl;
}

void generate(vector<int> v, int i) {
  if (i < 1) write(v, cout);
  else {
    for (int j = 0; j < 2; j++) {
      v[i] = j;
      generate(v, i - 1);
    }
  }
}

void generate_all(void)  {
  vector<int> number(N_DIGITS);
  number[0] = 0;
  generate(number, N_DIGITS - 1);
}


const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const int ALPHABET_size = (int)sizeof(ALPHABET) - 1;

void hacking(vector<char>& pw, int i = 0) {
  if (i = pw.size()) {
    cout << pw << " ";
  } else {
    for (int j = 0; j < ALPHABET_size; j++) {
      pw[i] = ALPHABET[j];
      hacking(pw, i + 1);
    }
  }
}