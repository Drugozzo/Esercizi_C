#include <stdio.h>

#define L 100
#define N 15

typedef char Stringa[N];

typedef struct{
	Stringa nominativo;
	int numero;
}Voce;

int main(void){
	
	Voce rubrica[L];
	int esc=0,i=0,j,c;

	printf("\nInserisci: 1\nVisualizza: 2\nEsci: 3\n\n");

	while(esc!=1){
		
		scanf("%d",&c);
		
		switch(c){

			case 1:
			printf("Nome: ");
			scanf("%s",rubrica[i].nominativo);
			printf("Numero: ");
			scanf("%d",&rubrica[i].numero);
			i++;
			break;

			case 2:
			for(j=0;j<i;j++){
				printf("Nome: %s ",rubrica[j].nominativo);
				printf("Numero: %d\n",rubrica[j].numero);
			}
			break;

			case 3:
			esc=1;
			break;
		}
	}


	return 0;
}