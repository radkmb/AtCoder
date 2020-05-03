#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d",&n);
    char s[n][11];
    
    for(int i = 0; i < n; i++) {
        scanf("%s",s[i]);
    }
    qsort(s, n, sizeof(char) * 11, strcmp);
    int count = 1;
    
    for(int i = 0; i < n - 1; i++) {
        if(strcmp(s[i], s[i + 1]) != 0)
            count++;
    }
    printf("%d",count);
    return 0;
}
