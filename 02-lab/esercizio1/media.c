#include <stdio.h>

int main(void){
	
	int n,ris=0,cont=0;
	
	do{
		scanf("%d",&n);
		ris=ris+n;
		cont++;
	}while(n!=0);
	ris=ris/cont;
	
	printf("%d\n",ris);

	return 0;
}