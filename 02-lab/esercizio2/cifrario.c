#include <stdio.h>

int main(void){
	
	int k;
	char c;

	scanf("%d",&k);
	do{

		c=getchar();
		if(c>=65 && c<=90){
			if(c+k>90)
				c=(c+k)-91+65;
			else
				c=c+k;
		}else{
			if(c>=97 &&c<=122){
				if(c+k>122)
					c=(c+k)-123+97;
				else
					c=c+k;
			}
		}
		printf("%c",c);

	}while(c!='\n');

	return 0;
}