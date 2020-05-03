#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d%d%d%d",&a, &b, &c, &d);
    
    while(a != 0 && c != 0) {
        c -= b;
        if(c <= 0) {
            break;
        }
        a -= d;
        if(a <= 0) {
            break;
        }
  }

  if(a > 0) {
      printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
