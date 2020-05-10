#include <stdio.h>
#include <string.h>

int main() {
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);
    
    if(a >= k) {
        printf("%d\n", k);
    } else if(a + b - k >= 0) {
        printf("%d\n", a);
    } else {
        printf("%d\n", a + (a + b - k));
    }
    return 0;
}
