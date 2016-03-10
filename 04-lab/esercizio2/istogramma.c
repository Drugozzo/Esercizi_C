#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void){
	
	char str[N],c;
	int i=0,j,a[26],n;


	while((c=getchar())!='.'){
		c=toupper(c);
		str[i]=c;
		i++;
	}

	for(j=0;j<i;j++)
		printf("%c",str[j] );

	printf("\n");

	for(j=0;j<26;j++)
		a[j]=0;

	for(j=0;j<i;j++){
		n=str[j]-'A';
		if(n>=0 || n<=25){
			a[n]++;
		}
	}


	for(j=0;j<26;j++){
		if(a[j]>0){
			i=j+'A';
			printf("%c: ",i);
			for(i=0;i<a[j];i++
				printf("*");
			printf("\n");
		}
	}

	return 0;
}