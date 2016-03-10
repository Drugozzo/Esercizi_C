#include <stdio.h>
#include <ctype.h>

#define N 20

char *maiuscolo( char *stringa );

int main(void){
	
	char s[N];

	scanf("%s",s);

	printf("%s\n",maiuscolo(s));

	return 0;
}

char *maiuscolo( char *stringa ){
	char *p;

	for(p=stringa;*p!='\0';p++){
		*p=toupper(*p);
	}
	return stringa;
}
