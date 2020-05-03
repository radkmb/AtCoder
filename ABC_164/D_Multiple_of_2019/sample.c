#include <stdio.h>
#include <math.h>

int i, j, k, t = 1, p = 0, m = 1e9+7, r = 0, a[2019];
char s[200001];

int main() {
    scanf("%s",s);

    for(i = 0; s[i] != '\0'; i++);
    for(j =-- i; i >= 0; i--) {
        p = (p + (s[i] - 48) * t) % 2019;
        t = (t * 10) % 2019;
        a[p]++;
    }
    for(i = 0; i < 2019; i++) {
        r += a[i] * (a[i] - 1) / 2;
    }
    printf("%d",r + a[0]);
    return 0;
}
