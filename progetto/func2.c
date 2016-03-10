#include <stdio.h>
#include <stdlib.h>
#include "func2.h"

char *ReadWord( void ){
	int size=2,n=0;
	char *p,*temp,c;

	p=malloc(size*sizeof(int));

	while(1){
		c=getchar();
		if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122)){
			p[n++]=c;
			if(n>=size){
				size*=2;
				temp=realloc(p,size*sizeof(int));
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

void NewNode(binTree *root){
	root = malloc(sizeof(binTree));
	root->l = NULL;
	root->r = NULL;
	
}

Persona NewUtente(Persona utente){
	utente.nome = malloc(12*sizeof(char *));
	utente.cognome = malloc(12*sizeof(char *));
	utente.nome = "ReadWord()";
	utente.cognome = "ReadWord()";
	/*scanf("%d",&utente.id);*/
	utente.id=rand();
	return utente;
}

void InsertUser(binTree *root){
	Persona utente;
	printf("Inserisci dati utente\n");
	utente = NewUtente(utente);
	//getchar();
	if(root == NULL){
		NewNode(root);
		root->utente = utente;
	}else{
		TryInsert(root, utente);
	}
}

void TryInsert(binTree *root, Persona utente){
	if(root->utente.id == utente.id){
		printf("Inserimento fallito, l'identificativo è già presente\n");
	}else{
		if(utente.id < root->utente.id){
			if(root->l == NULL){
				NewNode(root->l);
				root->l->utente = utente;
			}else{
				TryInsert(root->l,utente);
			}
		}else{
			if(root->r == NULL){
				NewNode(root->r);
				root->r->utente = utente;
			}else{
				TryInsert(root->r,utente);
			}
		}
	}
}

void printT(binTree *root){
	if(root != NULL){
		printf("[%p] ",&(root->l)); 
		printT(root->l);
		printf("%d ",root->utente.id);
		printT(root->r);
	}
}
