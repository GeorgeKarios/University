#include <stdio.h>
#define M_X 100

int main(){
    int matrix1[M_X][M_X], matrix2[M_X][M_X], M, N, P,i,j,k; 
	int final[M_X][M_X]={0};
    printf("Give 3 Matrix Dimensions(M*N & N*P)\n");
    scanf(" %d%d%d", &M, &N, &P);
    printf("Give the 1st Matrix %d * %d\n", M, N);
    for (i=0;i<M;i++)
        for(j=0;j<N;j++)
            scanf("%d",  &matrix1[i][j]);
    printf("\ngive the 2nd Matrix %d * %d\n",N, P);
    for (i=0;i<N;i++)
        for(j=0;j<P;j++)
            scanf("%d",  &matrix2[i][j]);
s
    for (i=0;i<M;i++)
        for (j=0;j<P;j++)
        	for (k = 0; k < N; k++)
            final[i][j]+= (matrix1[i][k] * matrix2[k][j]);
        
    for (i=0;i<M;i++){
        for (k=0;k<P;k++)
            printf(" %d", final[i][k]);
        printf("\n");
    }
    return 0;
}