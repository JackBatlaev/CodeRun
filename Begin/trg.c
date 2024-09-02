#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A,B,C; A = B = C = 0;
    scanf("%d %d %d", &A, &B, &C);

    if (((A + B) > C) && ((B + C) > A) && ((C + A) > B)) 
        printf("YES\n");
    else 
        printf("NO\n");

    return 0;
}