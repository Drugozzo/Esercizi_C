#include <stdio.h>
#include <stdlib.h>

typedef struct element element;

struct element{
	int info;
	element *next;
};

void insert(int n, element **head, int *count);
void printList(element *head);
int isMember(int n, element *head);
void delete(int n, element **head, int *count);
void destroy(element *head);
void printInv( element *head );

int main(void){

	element *head=NULL;
	int n,count=0;
	char c;

	printf("\n'+' Inserisci un valore nella lista\n'-' Elimina un elemento\n'?' Controlla se l'elemento è già inserito nella lista\n'c' Stampa il numero di elementi\n'p' Stampa la lista\n'o' Stampa gli elementi della lista nell'ordine inverso\n'd' Cancella tutti gli elementi dell'insieme\n'f' Esci\n\n");

	while((c=getchar())!='f'){
		switch(c){

			case '+':
			scanf("%d",&n);
			getchar();
			insert(n,&head,&count);
			break;

			case '-':
			scanf("%d",&n);
			getchar();
			delete(n,&head,&count);
			break;

			case '?':
			scanf("%d",&n);
			getchar();
			(isMember(n,head)==1)?(printf("\nL'elemento è presente nella lista\n")):(printf("\nL'elemento non è presente nella lista\n"));
			break;

			case 'c':
			getchar();
			printf("%d\n",count );
			break;

			case 'p':
			getchar();
			printList(head);
			break;

			case 'o':
			getchar();
			printInv(head);
			break;

			case 'd':
			getchar();
			destroy(head);
			head=NULL;
			break;
		}

		printf("\n'+' Inserisci un valore nella lista\n'-' Elimina un elemento\n'?' Controlla se l'elemento è già inserito nella lista\n'c' Stampa il numero di elementi\n'p' Stampa la lista\n'o' Stampa gli elementi della lista nell'ordine inverso\n'd' Cancella tutti gli elementi dell'insieme\n'f' Esci\n\n");
	}

	return 0;
}

void insert(int n, element **head, int *count){
	element *new_node;
	new_node=malloc(sizeof(element));
	if(isMember(n,*head)==0){
		new_node->info=n;
		new_node->next=*head;
		head=&new_node;
		*count+=1;
	}else
		printf("\nL'elemteno è già presente nella lista\n");
}

void printList(element *head){
	element *p;
	printf("\n");
	for(p=head;p!=NULL;p=p->next)
		printf("%d, ",p->info);
	printf("\n");
}

int isMember(int n, element *head){
	element *p;
	for(p=head;p!=NULL;p=p->next){
		if(n==p->info)
			return 1;
	}
	return 0;
}

void delete(int n, element **head, int *count){
	element *cur, *prev;
	for(cur=*head, prev=NULL; cur!=NULL && cur->info!=n; prev=cur,cur=cur->next);
	if(cur==NULL)
		return;
	if(prev==NULL)
		head = &head[0]->next;
	else
		prev->next = cur->next;
	free(cur);
	*count-=1;
	
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
