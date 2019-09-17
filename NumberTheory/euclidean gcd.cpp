unsigned euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}