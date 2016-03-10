#include <stdio.h>

#define N 20

int lung_stringa( char *s );

int main(void){
	
	char s[N];
	scanf("%s",s);
	printf("%d\n",lung_stringa(s) );
	return 0;
}

int lung_stringa( char *s ){
	char *p;
	int cont=0;

	for(p=s;*p!='\0';p++)
		cont++;

	return cont;
}	
