#include <stdio.h>
#include <math.h>

int main(void){
	
	float r,area;
	scanf("%f",&r);
	area= pow(r,2)*M_PI;
	printf("%f\n",area);

	return 0; 
}