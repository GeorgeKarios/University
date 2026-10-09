#include <stdio.h>
#define N 30
void numOfElements(float arr[],int length);

int main(){
    float arr[N];
    int i, length;
    printf("Enter Length\n");
    scanf("%d", &length);
    printf("Enter Array\n");
    for (i=0;i<length;i++)
        scanf("%f", &arr[i]);
    numOfElements(arr,length);
    printf("After:   ");
    for(i=0;i<length;i++)
        printf(" %.1f",arr[i] );
	return 0;
}

void numOfElements(float arr[],int length){
    float temp1,temp2 =arr[0];
    int i;
    for (i=1;i<length-2;i++){
        temp1=arr[i];
        arr[i]=(temp2+temp1+arr[i+1])/3;
        temp2=temp1;
    }
 }
