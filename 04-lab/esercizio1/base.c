#include <stdio.h>

#define N 100

int main(void){
	
	int n,b,a[N],i;

	scanf("%d%d",&b,&n);

	for(i=0;i<N;i++){
		a[i]=n%b;
		n=n/b;
		if(n<=0)
			break;
	}
	
	for(;i>=0;i--){
		printf("%d",a[i]);
	}

	return 0;
}