unsigned int bin(const unsigned int number) {
  return number > 1 ? (bin(number / 2) * 10 + number % 2) : number;
}