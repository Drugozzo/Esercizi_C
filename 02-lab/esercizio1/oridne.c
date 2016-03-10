#include <stdio.h>
#include <ctype.h>

int main(void){
	
	char c1,c2;
	int n;

	scanf("%c%c",&c1,&c2);
	c1=tolower(c1);
	c2=tolower(c2);

	n=c1-c2;
	if(n<0)
		n=-n;

	printf("%d\n",n);

	return 0;
}