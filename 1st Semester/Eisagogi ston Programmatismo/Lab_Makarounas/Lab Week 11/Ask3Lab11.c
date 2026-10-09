#include <stdio.h>
#include <math.h>
int main()
{
    int *p[3], i, j, k;
    p[0] = &i;
    p[1] = &j;
    p[2] = &k;
    printf("Enter length A and length B: ");
    scanf("%d%d", p[0], p[1]);
    printf("Enter length of C");
    do{
        scanf("%d", p[2]);
    } while (*p[2]<=*p[1]|| *p[2]<=*p[0]);

    if (pow(*p[1],2) + pow(*p[0],2) == pow(*p[2],2))
        printf("To Trigono einai Orthogonio\n");
    else if (pow(*p[1],2) + pow(*p[0],2)> pow(*p[2],2))
        printf("To Trigono einai Ambligonio\n");
    else
        printf("To Trigono einai Oxigono\n");
return 0;
}