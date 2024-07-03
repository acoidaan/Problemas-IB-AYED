int mcm(int a, int b, int divisor) {
  if (a < divisor || b < divisor) return a * b;
  if (a % divisor != 0 || b % divisor != 0) return mcm(a, b, divisor + 1);
  int x = (a % divisor == 0) ? a / divisor : a;
  int y = (b % divisor == 0) ? b / divisor : b;
  return divisor * mcm(x, y, divisor);
}