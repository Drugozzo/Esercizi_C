#include <stdio.h>

#define N 21

int main(void){
	
	int n,i,j,k,i1,j1,cont=1;

	scanf("%d",&n);

	int a[N][N];

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	
	for(k=0,j=(n/2),i=0;k<n*n;k++,cont++){
		a[i][j]=cont;
		//printf("i: %d, j: %d\n",i,j);
		if((i-1)<0)
			i1=n-1;
		else
			i1=i-1;;
		if((j+1)>=n)
			j1=0;
		else
			j1=j+1;
		if(a[i1][j1]!=0)
			i++;
		else{
			i=i1;
			j=j1;
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%3d ",a[i][j]);
		}
		printf("\n");
	}

	
	return 0;
}