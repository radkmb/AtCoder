#include <stdio.h>
 
int main(void) {
 
  long a, b, n;
  scanf("%ld %ld %ld",&a, &b, &n);
  long x = b - 1;
  if (x > n) {
    x = n;
  }
  long answer = a * x / b - a * (x / b);
  printf("%ld\n",answer);
  return 0;
}
