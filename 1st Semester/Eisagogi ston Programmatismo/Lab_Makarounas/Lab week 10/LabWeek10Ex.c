#include <stdio.h>
// #include <stdlib.h> 
// #include <time.h> 
#define N 10
int main( ){
    //srand(time(NULL));
    int len, magic[N][N], sumcol[N]= {0}, sumline[N]= {0}, sumD1=0, sumD2=0, base, flag =1,cord,i,j;
    printf("Input the Wanted Length N when (N*N)");
    scanf("%d", &len);
    while (len>10 || len<0){
        printf("Wrong number of Length, Enter again\n");
        scanf("%d", &len);
    }
    base = len*(len*len+1)/2;
    printf(" Enter A 2d array that is %d*%d",len, len);
    for (i=0;i<len;i++){
          for (j=0;j<len;j++)
                scanf("%d", &magic[i][j]);  // or magic[i][j]= (1+rand()%(len*len));    
    }   
    for (i=0;i<len;i++){
        printf("\n");
        for (j=0;j<len;j++){
            printf(" %d",magic[i][j]);
            sumcol[j]+= magic[i][j];
            sumline[i]+= magic[i][j];
            if (i==j)
                sumD1+=magic[i][j];
            if (len-1-i==j)
                sumD2+=magic[i][j];
        }
    }
    for (i=0;i<len;i++){
        if (sumcol[i]!=base){
            flag=0;
            cord=magic[len-1][i];
            break;
        }
        if (sumline[i]!=base){
            flag=0;
            cord= magic[i][len-1];
            break;
        }
    }
    if (sumD1 != base)
        flag=0;
        cord = magic[len-1][len-1];
    if (sumD2 != base)
        flag=0;
        cord = magic[len-1][0];
    if (flag==1)
        printf("\n is a magic square");
    else
        printf("\n is not a magic square, first error found at the line or column of the ending number %.2d ", cord);
return 0;
}