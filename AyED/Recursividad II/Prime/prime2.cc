bool prime(int n, int divisor = 2) {
  if (n == divisor) return true;
  return (n % divisor == 0) ? false : prime(n, divisor + 1);
}