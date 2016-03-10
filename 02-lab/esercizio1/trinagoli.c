#include <stdio.h>

int main(void){

	int l1,l2,l3;

	scanf("%d%d%d",&l1,&l2,&l3);

	int sum1=l1+l2, sum2=l2+l3, sum3=l1+l3;

	if(l3<sum1 && l1<sum2 && l2<sum3){
		if (l1==l2 && l1==l3)
			printf("triangolo equilatero\n");
		else{
			if(l1==l2 || l2==l3 || l3==l1)
				printf("triangolo isoscele\n");
			else
				printf("triangolo scaleno\n");
		}
	}else
		printf("non è un triangolo");

	return 0;
}