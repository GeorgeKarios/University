#include <stdio.h>
#define MX 100

int main (){
    int arr[MX][MX], COL, ROW, i , j;
    printf("Give Matrix Dimensions(ROW*COl)\n");
    scanf(" %d%d", &ROW, &COL);
    printf("\nArray %d * %d\n", ROW, COL);
    for (i=0;i<ROW;i++)
        for(j=0;j<COL;j++)
             scanf(" %d", &arr[i][j]);
	printf("\nArray In Reverse (%d * %d):\n" ,COL, ROW);
	for (i=0; i<COL;i++){
    	for (j=0;j<ROW;j++)
       		printf("%d ",arr[j][i]);
    	printf("\n");
	}
	return 0;
}