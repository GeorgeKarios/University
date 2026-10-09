#include<stdio.h>
int power(int, int);

int main(){
    int pow, num, final;
    printf("Enter an integer an the power");
    scanf(" %d %d", &num, &pow);
    final = power(num, pow);
    printf("%d", final);
    return 0;
}

int power(int num, int pow){
    if ( pow==1)
    	return num;
    else {
        return num*power(num, pow-1);
    }
}
