#include <stdio.h>
#define K 26
void check(int [][K], int);

int main(){
    int N, cit[K][K], i, j;
    printf("Enter the number of cities!\n");
    scanf("%d", &N);
    while (N>26 || N<1){
         printf("Wrong number of cities, Enter again\n");
         scanf("%d", &N);
    }
     printf("Now Enter the KM between each city!\n");
     for (i=0;i<N;i++){
          for (j=0;j<N;j++){
               scanf("%d", &cit[i][j]);
               while (cit[i][j]>999 || cit[i][j]<0){
                    printf("Wrong number of KM, Enter again\n");
                    scanf("%d", &cit[i][j]);
               }
          }
     }
     check(cit, N);
return 0;
}

void check(int cit[][K], int N){
    int sym=1, diag=1, cordX, cordY, j, i, pl=0;
          for (i=0;i<N;i++){
               for (j=0;j<N;j++){
                    if (i==j && cit[i][j]!=0){
                         diag=0;
                         if (pl==0){
                              cordY=i;
                              cordX=j;
                              pl++;
                         }
                    }
                    if (cit[i][j]!=cit[j][i]){
                         sym=0;
                         if (pl==0){
                              cordY=i;            //να γυγω τα pl και να καμω break
                              cordX=j;            // θα βοηθησει πολύ τo code 
                              pl++;
                         }    
                    }
               }
          }
     if(diag==1 && sym==1)
          printf("Mileage Chart Checks OK\n");
     else
    		printf("Mileage Chart In Error, First Error in Row:%d & Column:%d \n", cordY, cordX);
}