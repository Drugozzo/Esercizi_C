#include <stdio.h>

int main(void){

	int n,ris=0,cont=0;

	while(cont<10){
		scanf("%d",&n);
		if (n!=0){
			ris=ris+n;
			cont++;
		}
	}

	printf("%d\n",ris);
	return 0;
}