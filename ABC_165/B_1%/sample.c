#include <stdio.h>

int main() {
 long long int a, b = 0, c = 100, i = 1;
 scanf("%lld",&a);
  
  if(a == 100) {
    i = 0;
 } else {
   while(1) {
     b = c / 100;
     c += b;
     if(c >= a)
        break;
     i++;
   }
 }
  printf("%lld\n", i);
  return 0;
}
