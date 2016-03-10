#define N 100

#include <stdio.h>

int main(void){
	
	int a[N],i,n,j;

	for(i=0;i<N;i++){
		scanf("%d",&n);
		if(n==0){
			i--;
			break;
		}else
			a[i]=n;
	}

	for(j=i;j>=0;j--){
		printf("%d ",a[j]);
	}
	printf("\n");
	return 0;
}