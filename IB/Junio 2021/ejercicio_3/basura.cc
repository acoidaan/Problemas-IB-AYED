#include <iostream>
#include <cctype>
#include <string>

void Usage(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << " -- Cambio de mayusculas y minusculas" << std::endl;
    std::cout << "Modo de uso: " << argv[0] << " <word>" << std::endl;
    std::cout << "<word> debe ser una cadena de texto" << std::endl;
    exit(1);
  }
}

void SwitchCase(std::string& word) {
  for (char& character : word) {
    if (std::isupper(character)) {
      character = std::tolower(character);
    } else if (std::islower(character)) {
      character = std::toupper(character);
    }
    std::cout << character;
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string word = argv[1];
  SwitchCase(word);
  //std::cout << std::endl;
  return 0;
}