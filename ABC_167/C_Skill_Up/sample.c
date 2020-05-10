#include <stdio.h>

int main() {
  int n, m, x, ans = 1e9+7, i, j, k, a[20][20], b[20], c[20], s;
  scanf("%d %d %d",&n, &m, &x);
  
  for(i = 0; i < n; i++) {
      scanf("%d",&c[i]);
      for(j = 0; j < m; j++)
      scanf("%d",&a[i][j]);
    }
    for(i = 0; i < (1 << n); i++) {
        for(j = 0; j < n; j++)
        b[j] = 0;
        for(j = s = 0; j < n; j++) {
            if((i & (1 << j)) == 0)
            continue;
            s += c[j];
            for(k = 0; k < m; k++)
            b[k] += a[j][k];
        }
        for(j = 0; j < m; j++) {
            if(b[j] < x)
            goto NEXT;
        }
        if(ans > s)
        ans=s;
        NEXT:;
    }
    printf("%d\n",ans>1e9?-1:ans);
    return 0;
}
