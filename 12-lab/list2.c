#include <stdio.h>
#include <stdlib.h>

typedef struct element element;

struct element{
	int info;
	element *next;
};

typedef struct {
	int count; 
	element *head; 
} list;

list *insert(int n,list *l);
void printList(list *l);
int isMember(int n,list *l);
list *delete(int n,list *l);
void destroy(element *head);
void printInv(element *head );

int main(void){

	list list;
	int n;
	char c;
	list.head=NULL;
	list.count=0;
	/*list->head=NULL;
	list->count=0;*/

	printf("\n'+' Inserisci un valore nella lista\n'-' Elimina un elemento\n'?' Controlla se l'elemento è già inserito nella lista\n'c' Stampa il numero di elementi\n'p' Stampa la lista\n'o' Stampa gli elementi della lista nell'ordine inverso\n'd' Cancella tutti gli elementi dell'insieme\n'f' Esci\n\n");

	while((c=getchar())!='f'){
		switch(c){

			case '+':
			scanf("%d",&n);
			getchar();
			list=*insert(n,&list);
			break;

			case '-':
			scanf("%d",&n);
			getchar();
			list=*delete(n,&list);
			break;

			case '?':
			scanf("%d",&n);
			getchar();
			(isMember(n,&list)==1)?(printf("\nL'elemento è presente nella lista\n")):(printf("\nL'elemento non è presente nella lista\n"));
			break;

			case 'c':
			getchar();
			printf("%d\n",list.count );
			break;

			case 'p':
			getchar();
			printList(&list);
			break;

			case 'o':
			getchar();
			printInv(list.head);
			break;

			case 'd':
			getchar();
			destroy(list.head);
			list.head=NULL;
			list.count=0;
			break;
		}

		printf("\n'+' Inserisci un valore nella lista\n'-' Elimina un elemento\n'?' Controlla se l'elemento è già inserito nella lista\n'c' Stampa il numero di elementi\n'p' Stampa la lista\n'o' Stampa gli elementi della lista nell'ordine inverso\n'd' Cancella tutti gli elementi dell'insieme\n'f' Esci\n\n");
	}

	return 0;
}

list *insert(int n, list *l){
	element *new_node;
	if(isMember(n,l)==0){
		new_node=malloc(sizeof(element));
		new_node->info=n;
		new_node->next=l->head;
		l->head=new_node;
		l->count++;
	}else
		printf("\nL'elemteno è già presente nella lista\n");
	return l;
}

void printList(list *l){
	element *p;
	printf("\n");
	for(p=l->head;p!=NULL;p=p->next)
		printf("%d, ",p->info);
	printf("\n");
}

int isMember(int n, list *l){
	element *p;
	for(p=l->head;p!=NULL;p=p->next){
		if(n==p->info)
			return 1;
	}
	return 0;
}

list *delete(int n, list *l){
	element *cur, *prev;
	for(cur=l->head, prev=NULL; cur!=NULL && cur->info!=n; prev=cur,cur=cur->next);
	if(cur==NULL)
		return l;
	if(prev==NULL)
		l->head = l->head->next;
	else
		prev->next = cur->next;
	free(cur);
	l->count++;

	return l;
	
}

void destroy(element *head){
	if(head!=NULL)
		destroy(head->next);
	free(head);
}

void printInv( element *head ){
	if(head->next!=NULL)
		printInv(head->next);
	printf("%d ", head->info);
}

