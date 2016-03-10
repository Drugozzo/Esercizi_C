#include <stdio.h>

int main(void){
	
	int n,i,cont=0,k;

	printf("1: \n2: \n3:\n");
	scanf("%d",&k);

	scanf("%d",&n);
	switch(k){

		case 1:
		for(i=n;i>0;i--){
			if(n%i==0){
				printf("%d ",i);
				cont++;
			}
		}

		printf("\n%d\n",cont);
		break;

		case 2:
		for(i=n;i>0;i--){
			if(n%i==0)
				cont++;
		}
		(cont>0 && cont<=2)?(printf("primo\n")):(printf("non primo\n"));
		break;

		case 3:
		i=n;
		while(i>0){
			if(n%i==0)
				cont++;
			i--;	
		}
		(cont>0 && cont<=2)?(printf("primo\n")):(printf("non primo\n"));
	}
	return 0;
}