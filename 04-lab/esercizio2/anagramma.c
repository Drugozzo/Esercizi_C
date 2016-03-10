#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void){
	
	char str1[N],str2[N],c;
	int i=0,j,a1[26],a2[26],n,k=0,r=1;

	for(j=0;j<26;j++){
		a1[j]=0;
		a2[j]=0;
	}


	while((c=getchar())!='.'){
		c=toupper(c);
		str1[i]=c;
		i++;
	}

	for(j=0;j<i;j++){
		n=str1[j]-'A';
		if(n>=0 || n<=25){
			a1[n]++;
		}
	}

	while((c=getchar())!='.'){
		c=toupper(c);
		str2[k]=c;
		k++;
	}

	
	for(j=0;j<k;j++){
		n=str2[j]-'A';
		if(n>=0 || n<=25){
			a2[n]++;
		}
	}

	for(j=0;j<i;j++){
		printf("%c",str1[j] );
	}

	for(j=0;j<k;j++){
		printf("%c",str2[j] );
	}

	printf("\n");


	for(j=0;j<26;j++){
		printf("a1: %d, a2: %d\n",a1[j],a2[j]);
		if(a1[j]!=a2[j]){
			r=0;
			break;
		}
		printf("%d\n",n);
	}

	(r==1)?(printf("anagramma\n")):(printf("non anagramma\n"));


	return 0;
}