#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int *aux,i,a=0;
	aux=calloc(10,sizeof(int));
	for(i=0;i<10;i++){
		if(aux[i]!=0){
			printf("%d",aux[i]);
		}
		if(a){
			printf("\n");
		}
	}
	printf("\n");

	return 0;
}