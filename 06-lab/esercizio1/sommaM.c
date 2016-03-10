#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void ran(int a[][N],int n);

int somma(int a[][N], int n);

int main(void){
	
	int a[N][N],n,j,i;

	srand(time(NULL));
	n=rand()%N;
	ran(a,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n");

	printf("%d",somma(a,n));
	printf("\n");
	return 0;
}

void ran(int a[][N], int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=rand()%10000;
}

int somma(int a[][N],int n){
	int i,sum=0,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sum=sum+a[i][j];
	return sum;
}

