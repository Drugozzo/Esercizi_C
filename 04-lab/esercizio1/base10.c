#include <stdio.h>
#include <math.h>

#define N 100

int main(void){
	
	int b, a[N],i=0,j=0,ris,k;
	char s;

	scanf("%d",&b);

	while((s=getchar())!='.' && i<N){
		if(s!='\n'){
			a[i]=s-'0';
			i++;
		}
	}

	for(j=i-1,ris=0,k=0;j>=0;j--,k++){
		ris=ris+a[j]*pow(b,k);
		printf("a[j]: %d k: %d ris: %d\n ",a[j],j,ris );
	}

	printf("%d\n",ris);

	return 0;
}