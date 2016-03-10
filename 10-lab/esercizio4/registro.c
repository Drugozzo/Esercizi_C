#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct{
	char *name;
	int posto;
}Registro;*/

char *read_word( );
char **newBook(int n, char **r,int dim);
void book(int n, char *name,char **r);
void printBook(char **r,int dim);
void cancel(int k, char **r);
void move(int from, int to, char **r);

int main(void){

	char **registro=NULL;
	int n,k,dim=0,caso=0;
	char *s;

	while(caso!=7){
		printf("\n1) Crea Registro: \n2) Prenota posto:\n3) Cancella prenotazione:\n4) Sposta prenotazione:\n5) Stampa registro:\n6) Esci:\n\n");
		scanf("%d",&caso);
		getchar();

		switch(caso){

			case 1:
			printf("Inserisci il numero di posti: ");
			do{
				scanf("%d",&n);
			}while(n<0 || n>500);
			getchar();
			registro=newBook(n,registro,dim);
			dim=n;
			break;

			case 2:
			printf("Inserisci il posto da prenotare: ");
			do{
				scanf("%d",&n);
			}while(n<0 || n>500);
			getchar();
			printf("Inserisci il nome: ");
			s=read_word();
			if(registro==NULL)
				printf("GIOVANNI MILANI È UN RICCHIONE DIMMERDA\n");
			book(n,s,registro);
			free(s);
			s=NULL;
			printf("n: %d\n",dim);
			break;

			case 3:
			printf("Inserisci il numero del posto da cancellare: ");
			scanf("%d",&n);
			if(registro==NULL)
				printf("GIOVANNI MILANI È UN RICCHIONE DIMMERDA\n");
			cancel(n,registro);
			break;

			case 4:
			printf("Inserisci il numero della prenotazione da spostare: ");
			scanf("%d",&n);
			printf("Inserisci il numero della posizione da occupare:");
			scanf("%d",&k);
			if(registro==NULL)
				printf("GIOVANNI MILANI È UN RICCHIONE DIMMERDA\n");
			move(n,k,registro);
			break;

			case 5:
			if(registro==NULL)
				printf("GIOVANNI MILANI È UN RICCHIONE DIMMERDA\n");
			printBook(registro,dim);
			break;

			case 6:
			caso=7;
			break;
		}
	}

	return 0;
}

char *read_word(){
	int size=2,n=0;
	char *p,*temp,c;

	p=malloc(size*sizeof(char));

	while(1){
		c=getchar();
		if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122)){
			p[n++]=c;
			if(n>=size){
				size*=2;
				temp=realloc(p,size*sizeof(char));
				if(temp==NULL){
					break;
				}else{
					p=temp;
				}
			}
		}else{
			break;
		}
	}
	p[n]='\0';
	return p;
}

char **newBook(int n, char **r,int dim){
	int i;
	if(r!=NULL){
		for(i=0;i<dim;i++){
			free(r[i]);
			r[i]=NULL;
		}
		free(r);
		r=NULL;
	}
	r=malloc(n*sizeof(char*));
	for(i = 0; i < n; i++ ) {
		r[i]=malloc(sizeof(char));
		r[i]=NULL;
	}
	return r;
}

void book(int n, char *name,char **r){
	if(r[n]==NULL){
		r[n]=malloc(strlen(name)*sizeof(char));
		strcpy(r[n],name);	
	}else
		printf("ERRORE: il posto è già stato prenotato\n");
}

void cancel(int k, char **r){
	if(r[k]!=NULL){
		free(r[k]);
		r[k]=NULL;
	}else
		printf("ERRORE: il posto non è occupato\n");
}

void move(int from, int to, char **r){
	if(r[from]!=NULL && r[to]==NULL){
		r[to]=malloc(strlen(r[from])*sizeof(char));
		strcpy(r[to],r[from]);
		free(r[from]);
		r[from]=NULL;
	}else
		printf("NO\n");

}

void printBook(char **r, int dim){
	int i;
	for(i=0;i<dim;i++){
		printf("Posto numero: %d, ",i );
		if(r[i]==NULL)
			printf("Libero\n");
		else
			printf("Nome: %s\n",r[i]);
	}
	printf("\n");
}



