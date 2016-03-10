#include <stdio.h>

#define N 100

int main(void){
	
	int a[N],n,i=0,j,app,k;

	for(i=0;i<N;i++){
		app=0;
		scanf("%d",&n);
		if(n==0)
			break;
		for(j=0;j<i;j++){
			if(n<a[j]){
				for(k=i;k>j;k--)
					a[k]=a[k-1];
				a[j]=n;
				app=1;
				break;
			}
		}
		if(app==0)
			a[i]=n;

		
	}

	for(j=0;j<i;j++){
		printf("%d",a[j] );
	}
	printf("\n");

	return 0;
}