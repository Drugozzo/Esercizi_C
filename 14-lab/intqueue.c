
#include <stdio.h>
#include "intqueue.h"

intqueue *createqueue(void)
{
    intqueue *q = malloc(sizeof(intqueue));

    if(!q) {
        fprintf(stderr,"Errore di allocazione nella creazione della coda\n");
        exit(-1);
    };
    q->head = createlist();
    q->count = 0;
    return q;
}

void destroyqueue(intqueue *q)
{
	destroylist(q->head);
	free(q);
}

void enqueue(intqueue *q, int elem)
{
    insertatend(q->head, elem);
    q->count++;
}

int dequeue(intqueue *q)
{
    int e;

    if(!q->count){
        fprintf(stderr,"Errore: dequeue su coda vuota\n");
        exit(-2);
    };
    e = q->head->next->dato;
    delete(q->head->next);
    q->count--;
    return e;
}

char emptyq(intqueue *q)
{
    return !q->count;
}