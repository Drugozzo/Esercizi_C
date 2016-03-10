#include <stdio.h>
#include "intdummylist.h"

/* crea una lista vuota e ne restituisce il puntatore radice */
intlist *createlist(void)
{
    intlist *q = malloc(sizeof(intlist));

    if(!q) {
        fprintf(stderr,"Errore di allocazione nella creazione della lista\n");
        exit(-1);
    };
    q->next = q->prev = q;
    return q;
}

/* visita una lista e esegue su ogni elemento la funzione op */
void traverse(intlist *p, void (*op)(intlist *, intlist *))
{
	intlist *q;

	if(!p) return;
	for(q = p->next; q != p; q = q->next)
		(*op)(p,q);
}

/* stampa l'elemento puntato */
void printelem(intlist *p, intlist *q)
{
	printf("\t-------\n\t|%5d|\n\t-------\n\t|  %c  |\n\t---%c---\n\t",
			q->dato, q->next ? '.' : 'X', q->next ? '|' : '-');
	if(q->next != p)
		printf("   |   \n\t   V\n");
}

/* ritorna il numero di elementi nella lista */
int countlist(intlist *p)
{
	int i;
	intlist *q;
	
	if(!p || p == p->next)
		return 0;
	for(i = 1, q = p->next; q->next != p; q = q->next, i++);
	return i;
}

/* inserisce un elemento in testa alla lista */
void insert(intlist *p, int elem)
{
	intlist *q = malloc(sizeof(intlist));

	if(!q) {
		fprintf(stderr,"Errore nell'allocazione del nuovo elemento\n");
		exit(-1);	
	};
	q->dato = elem;
	q->next = p->next;
	p->next->prev = q;
	p->next = q;
	q->prev = p;
}

/* inserisce un elemento in coda alla lista */
void insertatend(intlist *p, int elem)
{
	intlist *q = malloc(sizeof(intlist));

	if(!q) {
		fprintf(stderr,"Errore nell'allocazione del nuovo elemento\n");
		exit(-1);	
	};
	q->dato = elem;
	q->prev = p->prev;
	p->prev->next = q;
	p->prev = q;
	q->next = p;
}


/* cancella l'elemento puntato da q dalla lista */
void delete(intlist *q)
{
	q->prev->next = q->next;
	q->next->prev = q->prev;
	free(q);	
}

/* distrugge la lista */
void destroylist(intlist *p)
{
	while(p->next != p)
		delete(p->next);
	free(p);
}

/* concatena la lista con radice q alla lista con radice p */
void listcat(intlist *p, intlist *q)
{
	if(p == p->next) {
		p->next = q->next;
		p->prev = q->prev;
	} else if(q != q->next) { 
		p->prev->next = q->next;
		q->next->prev = p->prev;
		q->prev->next = p;
		p->prev = q->prev;
	}
	if(q != q->next) 
		free(q);
}

/* restituisce vero se la funzione check e' vera su almeno un elemento */
char traverseandcheck(intlist *p, char (*check)(intlist *, int), int a)
{
	intlist *q;

	for(q = p->next; q != p; q = q->next)
		if((*check)(q,a))
			return 1;
	return 0;
}

/* restituisce il primo elemento per cui check e' vera oppure NULL*/
intlist *getcheckelem(intlist *p, char (*check)(intlist *, int), int a)
{
	intlist *q;

	for(q = p->next; q != p; q = q->next)
		if((*check)(q,a))
			return q;
	return NULL;
}

/* restituisce vero se p->dato == elem */ 
char checkexist(intlist *p, int elem)
{
	return p->dato == elem;
}

/* restituisce vero se l'elemento e' presente nella lista */
char existsinlist(intlist *p, int elem)
{
	return traverseandcheck(p,checkexist,elem);
}

/* restituisce il primo elemento q per cui q->dato == elem */
intlist *geteleminlist(intlist *p, int elem)
{
	return getcheckelem(p,checkexist,elem);
}