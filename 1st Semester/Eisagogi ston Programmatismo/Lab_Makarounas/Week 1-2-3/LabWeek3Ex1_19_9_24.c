#include <stdio.h>
int main(){
	float sal, cost, dan, AFTdan;
	int ax;
	int ans = 1;
	printf("Dose mistho & vathmo axiopistisas");
	scanf("%f%f",&sal,&ax);
	printf("Dose Kostos & Epithimito Daneio\n");
	scanf("%f%f",&cost,&dan);
	if (ax==4 || ax==3)
		AFTdan=(cost/100)*85;
	else if (ax==2)
		AFTdan=(cost/100)*75;
 	else if (ax==1)
		AFTdan=(cost/100)*50;
	else if (ax==0)
		AFTdan=(cost/100)*25;
		
	if (AFTdan>sal/2)
	ans = 0;
		
	printf("Tha pareis %f lefta",AFTdan);
	if (ans ==1)
		printf(" Kai ta Dikaiouse!!!!!");
	else if (ans==0)
		printf(" Alla DEN ta dikaiouse......!");
return 0;
}

