#include <stdio.h>

void scambia( int *p, int *q );

int main(void){
	
	int p,q;

	scanf("%d",&p);
	scanf("%d",&q),

	scambia(&p,&q);

	printf("p:%d, q: %d\n",p,q);

	return 0;
}

void scambia( int *p, int *q ){
	int i;
	i=*p;
	*p=*q;
	*q=i;
}
