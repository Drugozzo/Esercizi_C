#include <stdio.h>
#include <stdlib.h>

char **creaMat(int n);

int main(void){
	
	int n;
	char **m;

	scanf("%d",&n);
	m=creaMat(n);



	return 0;
}

char **creaMat(int n){
	char **m;
	int i;
	m=malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		m[i]=malloc(n*sizeof(char));
	return m;
}	
