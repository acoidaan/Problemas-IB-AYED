#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string SwitchCase(string word);

int main(int argc, char *argv[]) {
  string word = argv[1];
  cout << SwitchCase(word) << endl;
  return 0;
} 

string SwitchCase(string word) {
  string result;
  for (char c : word) {
    if (isupper(c)) result += tolower(c);
    else result += toupper(c);
  }
  return result;
}