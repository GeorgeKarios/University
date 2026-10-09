#include<stdio.h>
int factorial(int);

int main(){
    int fact=10;
    printf("%d", factorial(fact));
    return 0;
}

int factorial(int num){
    if (num>0){
        num*=factorial(num-1);
        return num;
    }
else
    return 1;
}