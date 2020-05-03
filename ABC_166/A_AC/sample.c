#include <stdio.h>

int main() {
  char s[100] = {};
  scanf("%s", s);
  
  if(s[1] == 'B') {
    printf("ARC\n");
  } else {
    printf("ABC\n");
  }
}
