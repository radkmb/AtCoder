#include <stdio.h>

int main() {
    int K, A, B, i = 1, mul;
    scanf("%d %d %d",&K, &A, &B);

    while(mul <= B) {
        mul = K * i;
        i++;
        if(mul >= A && mul <= B)
        break;
    }
    
    if(mul >= A && mul <= B)
       printf("OK\n");
       else
        printf("NG\n");
       return 0;
}
