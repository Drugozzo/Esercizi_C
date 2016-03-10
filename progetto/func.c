#include <stdlib.h>
#include <stdio.h>
#include "func.h"

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

binTree NewNode(binTree root){
	
	root = malloc(sizeof(binTree));
	root -> l = NULL;
	root -> r = NULL;
	return root;
}

binTree InsertUser(binTree root){
	Persona utente;
	
	utente.nome = malloc(sizeof(char *));
	utente.cognome = malloc(sizeof(char *));
	printf("Nome: ");
	utente.nome = read_word();
	printf("Cognome: ");
	utente.cognome = read_word();
	printf("ID: ");
	scanf("%d",&utente.id);
	if(root==NULL){
		getchar();
		root = NewNode(root);
		root->utente = utente;
	}else{
		getchar();
		TryInsert(root,utente);
	}
	return root;
	
}

void TryInsert(binTree root, Persona utente){
	if(utente.id == root->utente.id)
		printf("Inserimento fallito, l'identificativo è già presente\n");
	else{
		if(utente.id < root->utente.id){
			if(root->l == NULL){
				//printf("L");
				root->l = NewNode(root->l);
				root->l->utente = utente;
			}else{
				printf("L\n");
				TryInsert(root->l,utente);	
			}
		}else{
			if(root->r == NULL){
				//printf("R");
				root->r = NewNode(root->r);
				root->r->utente = utente;
			}else{
				printf("R\n");
				TryInsert(root->l, utente);
			}
		}
	}

}

/*void TryInsert(binTree root, Persona u){
	if(root == NULL){
		printf("%p\n",root );
		root = NewNode(root);
		root->utente = *u;
	}
	else{
		if(u->id == root->utente.id)
			printf("Inserimento fallito, l'identificativo è già presente\n");
		else{
			if(u->id < root->utente.id){
				printf("L");
				TryInsert(root->l, u);
			}
			else{
				printf("R");
				TryInsert(root->r, u);
			}
		}
	}
}*/

/*void SearchUser(binTree root, int id){
	if(root == NULL)
		printf("Utente non trovato\n");
	else{
		if(root->utente.id == id)
			printf("%s %s %d\n",root->utente.nome, root->utente.cognome, root->utente.id);
		else{
			if(id < root->utente.id)
				SearchUser(root->l,id);
			else
				SearchUser(root->r,id);
		}
	}

}*/
