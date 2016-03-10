#include <stdio.h>
#include <stdlib.h>

#define N 100

void max_secondmax ( int a[], int n, int *max, int *second_max );

int main(void){
	
	int a[N], n,i , max, second_max;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	max_secondmax(a,n,&max,&second_max);

	printf("no\n");

	printf("%d, %d\n",max,second_max );

	return 0;
}

void max_secondmax ( int a[], int n, int *max, int *second_max ){
	int *p;

	for(p=(a+1),*max=a[0],*second_max=a[0];p<(a+n);p++){
		if(*p>*max){
			*second_max=*max;
			*max=*p;
		}
		printf("ciao\n");
	}
}
