#include <stdio.h>
#include <string.h>

#define N 100
#define L 15

int main(void){
	
	char str[N],c;
	int i,cont=0,j,cancellato=0;

	while((c=getchar())!='\n' && cont<N){
		str[cont]=c;
		cont++;
	}

	c=str[cont-1];

	for(i=0;i<cont-1;i++){
		if(str[i]==c){
			for(j=i+1;j<cont;j++){
				str[j-1]=str[j];
			}
			cont--;
		}
		printf("%c",str[i]);
	}

	printf("\n");


	return 0;
}