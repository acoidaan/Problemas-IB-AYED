#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string RotateVowels(const string& text) {
  string rotated_text = text;
  for (char& character : rotated_text) {
    switch (character) {
      case 'a':
        character = 'e';
        break;
      case 'e':
        character = 'i';
        break;
      case 'i':
        character = 'o';
        break;
      case 'o':
        character = 'u';
        break;
      case 'u':
        character = 'a';
        break;
      default:
      break;
    }
  }
    return rotated_text;
}

int main(int argc, char *argv[]) {
  string filename = argv[1];
  ifstream file(filename);
  string line;
  while(getline(file, line)) {
    cout << RotateVowels(line) << endl;
  }

  file.close();
  return 0;
}



