#include <stdio.h>
#define N 5
int main( ){
    double arr[]= {1.3, -4.1,-3.8, 9.4, 2.5}, temp, *p1 = arr;
    int i;
    for (i=0;i<N/2;i++){   //den einai anagki na ftasei mexri to telos
        temp = *(p1+i);
        *(p1+i)= *(p1+N-1-i);
        *(p1+N-1-i)= temp;
    }
     for (i=0;i<N;i++)
        printf("%lf ,", *(p1+i));
    return 0;
}