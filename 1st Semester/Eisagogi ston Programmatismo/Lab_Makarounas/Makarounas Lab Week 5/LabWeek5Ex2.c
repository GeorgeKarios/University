#include<stdio.h>
int fibonacci(int);

int main(){
    int num, final;
    printf("Enter a Number\n");
    scanf("%d", &num);
    final = fibonacci(num);
    printf("fibonacci of %d = %d", fbn, final);
    return 0;
}

int fibonacci(int num){
    if (num==0||num==1)
        return num;
    else
    	return fibonacci(num-1)+fibonacci(num-2);
}
