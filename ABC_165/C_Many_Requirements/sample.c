#include <stdio.h>

int max = 0;
int n, m, q;
int s[15];
int a[60], b[60], c[60], d[60];

void roop(int k, int l) {
  int i, sum = 0;
  int j;
  
  if(k > n) {
    return;
  }
  if(k == n) {
    for(i = 0; i < q; i++) {
      if(s[b[i] - 1] - s[a[i] - 1] == c[i]){
        sum += d[i];
      }
    }
    if(max < sum) {
      max = sum;
    }
  }
  if(l > m) {
    return;
  }
  roop(k, l + 1);
  s[k] = l;
  roop(k + 1, l);
  return;
}

int main(void) {
  int i;
 
  scanf("%d%d%d",&n, &m, &q);
  for(i = 0; i < q; i++) {
    scanf("%d%d%d%d",&a[i], &b[i], &c[i], &d[i]);
  }
  roop(0, 1);
  printf("%d\n",max);
  return 0;
}
