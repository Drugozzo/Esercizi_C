#include <stdio.h>

#define N 100

int main(void){
	
	int n,a[N],i=0,cont=0,r=1,j;

	scanf("%d",&n);
	printf("%d\n",n );
	while(n>0){
		a[i]=n%10;
		n=n/10;
		i++;
		cont++;
	}

	for(i=0;i<=cont;i++){
		n=a[i];
		for(j=0;j<=cont;j++){
			if(n==a[j] && i!=j)
				r=0;
		}
		if (r==0)
			break;
	}

	(r==0)?(printf("doppie\n")):(printf("non doppie\n"));

	return 0;
}