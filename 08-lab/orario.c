#include <stdio.h>

void split_time ( long int tot_sec, int *h, int *m, int *s );

int main(void){

	long int n;
	int h,m,s;

	scanf("%ld",&n);

	split_time(n,&h,&m,&s);

	printf("h: %d, m: %d, s:%d\n",h,m,s);
	return 0;
}

void split_time ( long int tot_sec, int *h, int *m, int *s ){
	*h=tot_sec/3600; 
	tot_sec%=3600;
	*m=tot_sec/60;
	*s=tot_sec%60;
}
