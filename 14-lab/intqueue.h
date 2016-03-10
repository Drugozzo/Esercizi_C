#include "intdummylist.h"

struct intqueue {
    intlist *head;
    int count;
};

typedef struct intqueue intqueue;

intqueue *createqueue(void);

void destroyqueue(intqueue *);

void enqueue(intqueue *,int);

int dequeue(intqueue *);

char emptyq(intqueue *);

/* End of file intqueue.h */