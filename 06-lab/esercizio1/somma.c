#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void ran(int a[],int n);

int somma(int a[], int n);

int main(void){
	
	int a[N],n,i;

	srand(time(NULL));
	n=rand()%N;
	ran(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i] );
	printf("\n");

	printf("%d",somma(a,n));
	printf("\n");
	return 0;
}

void ran(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		a[i]=rand()%10000;
}

int somma(int a[],int n){
	int i,sum=0;
	for(i=0;i<n;i++)
		sum=sum+a[i];
	return sum;
}

