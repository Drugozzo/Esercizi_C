#include <stdio.h>

#define N 100

int main(void){
	
	int n, a[N],i;
	float f;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	printf("%d\n",a[n-1] );

	f=1/a[n-1];

	for(i=n-2;i>=0;i--){
		f=1/(a[i]+f);
	}

	printf("%f\n",f);

	return 0;
}