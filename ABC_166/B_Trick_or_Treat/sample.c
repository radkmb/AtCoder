#include <stdio.h>
#include <string.h>

int main() {
  int N = 0, K = 0;
  int i = 0, j = 0;
  int c = 0;
  int count = 0;
  scanf("%d",&N);

  int b[N];
  for(i = 0; i < N; i++) {
      b[i] = 1;
  }
  scanf("%d",&K);
  
  for(i = 0; i < K; i++) {
    int d = 0;
    scanf("%d",&d);
    
    for(j = 0; j < d; j++) {
      scanf("%d",&c);
      b[c - 1] = 0;
    }
  }

  for(i = 0; i < N; i++) {
    if(b[i] == 1)
      count += 1;
  }
  printf("%d",count);
  return 0;
}
