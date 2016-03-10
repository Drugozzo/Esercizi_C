#include <stdio.h>

#define N 100

int *smallest( int a[], int n );

int main(void){
	
	int a[N],n,i,*p;

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	p=smallest(a,n);

	printf("\n%d\n", *p);

	return 0;
}

int *smallest( int a[], int n ){
	int *p,*min;
	for(p=(a+1),min=a;p<a+n;p++){
		if(*p<*min)
			min=p;
	}

	return min;
}
