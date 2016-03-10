#include <stdio.h>

int main(void){
	float far;
	scanf("%f", &far);
	far = (far-32)/1.8;
	printf("%f\n", far);
	return 0;
}