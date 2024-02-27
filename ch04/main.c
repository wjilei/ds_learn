#include <stdio.h>


static int gcd(int p, int q) {
  int r;
  if(q == 0) return p;
  r = p % q;
  return gcd(q,r);
}
int main() {
  printf("%d\n", gcd(12,18));
  return 0;
}
