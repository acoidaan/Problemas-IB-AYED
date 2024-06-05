#include <iostream>
#include <cctype>
#include <string>

void SwitchCase(std::string& word) {
  for (char& character : word) {
    if (std::isupper(character)) {
      character = std::tolower(character);
    } else if (std::islower(character)) {
    character = std::toupper(character);
    }
  }
}

int main() {
  std::string word;
  std::cin >> word;
  SwitchCase(word);
  std::cout << word << std::endl;
  return 0;
}