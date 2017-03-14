bool IsPrime(int64_t n) {
  for (int64_t i = 2; i*i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
