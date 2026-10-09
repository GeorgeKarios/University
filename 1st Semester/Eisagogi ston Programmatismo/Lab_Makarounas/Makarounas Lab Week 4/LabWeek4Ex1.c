#include<stdio.h>
#include<math.h>

int cubesum (int n1, int n2, int n3, int n4);
float avgqrsum( int n1, int n2, int n3 , int n4);
int inrange (int num);
void equation(int n1, int n2, int n3, int n4, char cd);

int main(){
    int num1, num2, num3 ,num4, flg =1;
    char code;
    printf("Input the data, numbers must be from 10 to 20!\n");
    scanf(" %c %d %d %d %d", &code, &num1, &num2, &num3, &num4);
    if ((code!='S')&&(code!='C')&&(code!='A')){
        printf("INVALID  FUNCTION DATA\n");
        flg =0;}
    if (inrange(num1)){
        printf("INVALID 1st NUMBER DATA\n");
        flg =0;}
    if (inrange(num2)){
        printf("INVALID 2nd NUMBER DATA\n");
        flg =0;}
    if (inrange(num3)){
        printf("INVALID 3rd NUMBER DATA\n");
        flg =0;}
    if (inrange(num4)){
        printf("INVALID 4th NUMBER DATA\n");
        flg =0;}
    if (flg)    
    	equation(num1, num2, num3, num4, code);
    return 0;
}

int inrange(int num){
    if (num<10 || num>20)
        return 1; 
	return 0;
}

float avgqrsum(int n1, int n2, int n3, int n4){
    return ((n1*n1)+(n2*n2)+(n3*n3)+(n4*n4));
}

int cubesum(int n1, int n2, int n3, int n4){
    return (pow(n1,3)+pow(n2,3)+pow(n3,3)+pow(n4,3));
}
void equation(int n1, int n2, int n3, int n4, char cd){
    switch (cd){
        case 'S': printf("SUM OF THE SQUARES: %f\n", avgqrsum( n1, n2, n3, n4));
             break;
        case 'C': printf("SUM OF THE CUBES: %d\n", cubesum(n1, n2, n3,n4));
             break;
        case 'A': printf("AVERAGE OF THE SQUARES: %.2f\n", (avgqrsum(n1, n2, n3, n4)/4));
             break;
    }
}
