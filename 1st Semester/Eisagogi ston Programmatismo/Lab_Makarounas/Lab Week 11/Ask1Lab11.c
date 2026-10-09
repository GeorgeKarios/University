#include <stdio.h>
#define N 10
int main( ){
    int *p1,*p2;
    int  arr[N], arr2[N],i;
    p1= arr;
    p2= arr2;
    printf("Instert 10 Numbers in the 1st Array\n");
    for (i=0;i<N;i++)
        scanf("%d", (arr+i));
    printf("Instert 10 Numbers in the 2nd Array\n");
    for (i=0;i<N;i++)
        scanf("%d", (arr2+i));
    for (i=0;i<N;i++){
        if(*(arr2+i)== *(arr+i)){
            printf("The number %d is located in both arrays in the index of #%d \n", *(arr+i), i);
        }
    }
    return 0;
    }