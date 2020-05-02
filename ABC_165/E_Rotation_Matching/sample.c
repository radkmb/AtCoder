#include <stdio.h>

int main() {
  int n, m, num, i, as = 1, bs;
  scanf("%d%d",&n, &m);
  bs = n / 2 + n % 2 + 1;
  num = bs;
  for(i = 0; i < m; i++) {
    if(i % 2 == 0) {
      printf("%d %d\n",as, num - as);
      as++;
    } else {
      if(n % 2 != 0)
        printf("%d %d\n",bs, n - bs + num);
      else
        printf("%d %d\n",bs, n - bs + num - 1);
      bs++;
    }
  }
  return 0;
}
