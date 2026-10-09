#include <stdio.h>
#define N 30
int main (){
    int item, length,i, list[N],cnt=0, placeholder,tmp1;
    printf("Enter Length\n");
    scanf("%d", &length);
    printf("Enter List\n");
    for (i=0;i<length;i++)
        scanf("%d", &list[i]);
    printf("Enter Item\n");
    scanf("%d", &item);
    
    printf("item= %d\n Prin: Length:= %d \n        List: " , item, length);
    for (i=0;i<length;i++){
        printf("%d ",list[i]);
        if (list[i]==item){
            if (cnt==0)
                placeholder = i;
            cnt++;
        }
    }
    printf("\n");

    while(list[length-1]!=item){
        for (i=placeholder; i<length-cnt; i++){
            tmp1=list[i];
            list[i]=list[i+cnt];
            list[i+cnt]=tmp1;
        }
    }
    printf("Meta: Length:= %d \n       List:", length-cnt);
    for (i=0;i<length-cnt;i++)
         printf("%d ",list[i]);
    return 0;
}
