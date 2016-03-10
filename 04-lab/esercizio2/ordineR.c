#include <stdio.h>
#include <string.h>

#define L 100
#define N 15

typedef char Stringa[N];

typedef struct{
	Stringa nominativo;
	int numero;
}Voce;

int main(void){
	
	Voce rubrica[L];
	Stringa nom;
	int esc=0,i=0,j,c,k,num,cont=0,app;

	printf("\nInserisci: 1\nVisualizza: 2\nEsci: 3\n\n");

	while(esc!=1){
		
		scanf("%d",&c);
		
		switch(c){

			case 1:
			printf("Nome: ");
			scanf("%s",nom);
			printf("Numero: ");
			scanf("%d",&num);
			for(i=0;i<cont;i++){
				if(strcmp(nom,rubrica[i].nominativo)<0){
					for(k=cont;k>i;k--){
						strcpy(rubrica[k].nominativo,rubrica[k-1].nominativo);
						rubrica[k].numero=rubrica[k-1].numero;
					}
					strcpy(rubrica[i].nominativo,nom);
					rubrica[i].numero=num;
					app=1;
					break;
				}
			}
			if(app==0){
				strcpy(rubrica[cont].nominativo,nom);
				rubrica[cont].numero=num;
			}else
				app=0;
			cont++;
			break;

			case 2:
			for(j=0;j<cont;j++){
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