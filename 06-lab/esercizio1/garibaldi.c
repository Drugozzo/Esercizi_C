#include <stdio.h>

#define N 100

char cambia(char b, char c);

int main(void){
	
	char b,c,s[N];
	int count=0,i;

	b=getchar();
	getchar();

	while((c=getchar())!='.' && count<N){
		s[count]=c;
		count++;
	}

	for(i=0;i<count;i++)
		printf("%c",cambia(b,s[i]));
	
	printf("\n");

	return 0;
}

char cambia(char b, char c){
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
		return b;
	else
		return c;
}
