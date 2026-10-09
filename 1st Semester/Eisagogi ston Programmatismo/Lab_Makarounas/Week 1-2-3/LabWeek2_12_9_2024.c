#include<stdio.h> 
#include<math.h>
int main(){
float A, B, C, rt1, rt2;
printf(" insert veriables A, B, C");
scanf("%f%f%f", &A, &B, &C);
if (A==0){
	printf("***equatuion not quadric - cannot solve***");
}
else if ((pow(B,2)-4*A*C)==0){
	rt1=(-B+sqrt(pow(B,2)-4*A*C)/2*A);
	printf("***root=%.3f",rt1);
	printf("			 ONE ROOT ONLY");
}
else if (((pow(B,2)-4*A*C)/2*A)<0){
	printf("***equatuion not quadric - cannot solve***");
}
else {
	rt1=(float)(-B+sqrt(pow(B,2)-4*A*C)/2*A);
	rt2=(float)(-B-sqrt(pow(B,2)-4*A*C)/2*A);
	printf("root1= %.3f",rt1);
	printf("			root2= %.3f",rt2);
}
return 0;
}

