#include<stdio.h>
void Reverse();

int main(){
    printf("Instert Your Sentence!");
    Reverse();
    return 0;
}

void Reverse(){
	char ch;        
         if((ch = getchar())!= EOF && ch !='\n' ) 
            Reverse();
         if (ch=='\n')
         	printf("The reverse is:");
         printf("%c", ch);
}
