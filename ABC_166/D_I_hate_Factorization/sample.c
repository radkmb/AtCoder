#include <stdio.h>

int main() {
  long x;
  scanf("%ld",&x);

  for(int a = 0; a <= 200; a++) {
    for(int b =- 200; b <= 200; b++) {
      if(a * a * a * a * a - b * b * b * b * b == x) {
          printf("%d %d",a, b);
          return 0;
        }
    }
  }
}
