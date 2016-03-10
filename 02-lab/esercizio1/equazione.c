#include <stdio.h>
#include <math.h>

int main(void){

	int a, b, c;
	float ris1,ris2;

	scanf("%d%d%d", &a,&b,&c);

	ris1 = -b +sqrt(pow(b,2)-4*a*c);
	ris2 = -b -sqrt(pow(b,2)-4*a*c);

	printf ("%f\n%f\n",ris1,ris2);
	return 0;
}