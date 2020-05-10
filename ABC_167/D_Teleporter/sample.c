#include <stdio.h>

int main() {
  int n, a[200005];
  long long int k;
  scanf("%d %lld", &n, &k);

  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  long long int counter = 0;
  int visited[200005] = {0};
  int route[200005] = {0};
  int heiro[200005] = {0};
  int nowplace = 1;
  int flag = 0;
  visited[1] = 1;

  while(route[0] < k) {
      route[++route[0]] = nowplace;
      nowplace = a[nowplace];
      if(visited[nowplace]) {
          int count = 0;
          heiro[++heiro[0]] = route[route[0]];
          while(route[route[0] - count] != nowplace) {
              count++;
              heiro[++heiro[0]] = route[route[0] - count];
            }
            flag = 1;
            break;
            
            } else {
                visited[nowplace] = 1;
            }
    }
    
    if(flag) {
        int ans = heiro[heiro[0] - (k - route[0]) % heiro[0]];
        printf("%d\n", ans);
    } else {
        printf("%d\n", nowplace);
    }
    return 0;
}
