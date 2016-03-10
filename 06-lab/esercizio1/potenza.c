#include <stdio.h>

int pote(int b, int e);

int main(void){

	int b,e,ris;

	scanf("%d",&b);
	scanf("%d",&e);

	ris=pote(b,e);

	printf("%d\n",ris );

	return 0;
}

int pote(int b, int e){
	int ris=1,i;
	for(i=1;i<=e;i++)
		ris=ris*b;
	return ris;
}
