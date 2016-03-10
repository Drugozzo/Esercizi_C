#include <stdio.h>

int main(void){
	
	int n,ris=0;
	
	do{
		scanf("%d",&n);
		ris=ris+n;
	}while(n!=0);
	
	printf("%d\n",ris);

	return 0;
}