#include <stdio.h>
#include <string.h>

int main()
{
    char s1[12], s2[12];
    scanf("%s %s", s1, s2);
    
    for(int i = 0; i <strlen(s1); i++) {
        if(s1[i] != s2[i]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
