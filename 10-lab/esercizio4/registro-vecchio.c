#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct{
	char *name;
	int posto;
}Registro;*/

char *read_word( );
Registro **newBook(int n, Registro **r,int dim);
void book(int n, char *name,Registro **r);
void printBook(Registro **r,int dim);
void cancel(int k, Registro **r);
void move(int from, int to, Registro **r);

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
			scanf("%d",&n);
			getchar();
			registro=newBook(n,registro,dim);
			dim=n;
			break;

			case 2:
			printf("Inserisci il posto da prenotare: ");
			scanf("%d",&n);
			getchar();
			printf("Inserisci il nome: ");
			s=read_word();
			book(n,s,registro);
			free(s);
			s=NULL;
			printf("n: %d\n",dim);
			break;

			case 3:
			printf("Inserisci il numero del posto da cancellare: ");
			scanf("%d",&n);
			cancel(n,registro);
			break;

			case 4:
			printf("Inserisci il numero della prenotazione da spostare: ");
			scanf("%d",&n);
			printf("Inserisci il numero della posizione da occupare:");
			scanf("%d",&k);
			move(n,k,registro);
			break;

			case 5:
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

Registro **newBook(int n, Registro **r,int dim){
	int i;
	if(r!=NULL){
		for(i=0;i<dim;i++){
			free(r[i]);
			r[i]=NULL;
		}
		free(r);
		r=NULL;
		printf("%p\n",r );
	}
	r=malloc(n*sizeof(Registro));
	for(i = 0; i < n; i++ ) {
		r[i]=malloc(sizeof(Registro));
		r[i]->name=NULL;
		r[i]->posto=i;
	}
	return r;
}

void book(int n, char *name,Registro **r){
	if(r[n]->name==NULL || (strcmp(r[n]->name,""))==0){
		r[n]->name=malloc(strlen(name)*sizeof(char));
		strcpy(r[n]->name,name);	
	}else
		printf("ERRORE: il posto è già stato prenotato\n");
}

void cancel(int k, Registro **r){
	if(r[k]->name!=NULL){
		free(r[k]);
		r[k]->name=NULL;
	}else
		printf("ERRORE: il posto non è occupato\n");
}

void move(int from, int to, Registro **r){
	if(r[from]->name!=NULL && r[to]->name==NULL){
		r[to]->name=malloc(strlen(r[from]->name)*sizeof(char));
		strcpy(r[to]->name,r[from]->name);
		free(r[from]->name);
		r[from]->name=NULL;
	}else
		printf("NO\n");

}

void printBook(Registro **r, int dim){
	int i;
	for(i=0;i<dim;i++){
		printf("Posto numero: %d, ",r[i]->posto );
		if(r[i]->name==NULL)// || (strcmp(r[i]->name,""))==0)
			printf("Libero\n");
		else
			printf("Nome: %s\n",r[i]->name);
	}
	printf("\n");
}



