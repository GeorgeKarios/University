#include <stdio.h>
int main(){
	int flg = 0;
	float cnt=0, num=1;
	printf("Dose Arithmous");
	while (num != 0){
		scanf("%f",&num);
		if (num>0 ){
			cnt+=num;
			flg=1;
		}
	}
	printf("Sinoliko Sum=%f",cnt);
	if (flg==0)
		printf("To Programma den exei kanena Thetiko Arithmo");
	return 0;
	}
