#include<stdio.h>
int main(){
    int cnt=0;
    char CHR;
    printf("Dose Keimeno & patise (CTRL + Z) gia na stamatiseis\n");
    while ((CHR = getchar())!= EOF){
            if (CHR != ' ' && CHR != '\n')
            cnt++;
    }
    printf("o arithmos ton xaraktiron xoris ta keno kai tis allages grammon einai: %d", cnt);
    return 0;
}
