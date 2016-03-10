#include <stdio.h>

void isprimo(int n);

int main(void){
	
	int n;

	scanf("%d",&n);
	isprimo(n);

	return 0;
}

void isprimo(int n){
	int i,cont=0;
	for(i=2;i<n;i++){
		if(n%i==0) cont=1;
	}

	(cont==1)?(printf("non è primo\n")):(printf("è primo\n"));
}
