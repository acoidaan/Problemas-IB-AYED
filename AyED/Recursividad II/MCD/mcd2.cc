int mcd(int a, int b, int divisor) {
  if (a < divisor || b < divisor) return 1;
  return (a % divisor == 0 && b % divisor == 0) ?  divisor * mcd(a / divisor, b / divisor, divisor) : mcd(a, b, divisor + 1);
}