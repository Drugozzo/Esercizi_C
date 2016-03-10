#include <stdio.h>

#define N 100

int main(void){
	
	char c, s[N], *p,*q,*r,cont=-1;
	int pal=1;
	p=s;

	while((c=getchar())!='.' && p<(s+N)){
		*p=c;
		p++;
		cont++;
	}

	for(q=s;q<p;q++){
		printf("%c", *q);
	}
	printf("\n");

	p--;

	for(q=(p),r=(p);q>=s;q--){
		printf("%c",*q);
	}

	printf("\n");

	for(q=s;q<&s[cont/2] && p>&s[cont/2];q++,p--){
		if(*q!=*p){
			pal=0;
			break;
		}
	}

	(pal==1)?(printf("palindorma\n")):(printf("non palindroma\n"));



	return 0;
}
