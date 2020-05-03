#include <stdio.h>

int main() {
  int n, m, ans = 0;
  
  scanf("%d%d",&n, &m);
  
  long h[n + 1];
  int a[m + 1], b[m + 1], c[n + 1];
  
  for(int i = 1; i <= n; i++) {
    c[i] = 0;
  }
  
  for(int i = 1; i <= n; i++) {
    scanf("%ld",&h[i]);
  }
  for(int i = 1; i <= m; i++) {
    scanf("%d%d",&a[i], &b[i]);
  }
  
  for(int i = 1; i <= m; i++) {
    if(h[a[i]] > h[b[i]]) {
		c[b[i]] = 1;
	}
    if(h[a[i]] < h[b[i]]) {
		c[a[i]] = 1;
	}
    if(h[a[i]] == h[b[i]]) {
		c[b[i]] = 1;
		c[a[i]] = 1;
	}
  }
  
  for(int i = 1; i <= n; i++) {
    if(c[i] == 0) {
		ans += 1;
	}
  }
  printf("%d",ans);
}
