#include <stdlib.h>

struct intlist {
    int dato;
    struct intlist *next, *prev;
};

typedef struct intlist intlist;

/* crea una lista vuota e ne restituisce il puntatore radice */
intlist *createlist(void);

/* visita una lista e esegue su ogni elemento la funzione op */
void traverse(intlist *p, void (*op)(intlist *, intlist *));

/* stampa l'elemento puntato */
void printelem(intlist *p, intlist *q);

/* ritorna il numero di elementi nella lista */
int countlist(intlist *p);

/* inserisce un elemento in testa alla lista */
void insert(intlist *p, int elem);

/* inserisce un elemento in coda alla lista */
void insertatend(intlist *p, int elem);

/* cancella l'elemento puntato da q dalla lista */
void delete(intlist *q);

/* distrugge la lista */
void destroylist(intlist *p);

/* concatena la lista con radice q alla lista con radice p */
void listcat(intlist *p, intlist *q);

/* restituisce vero se la funzione check e' vera su almeno un elemento */
char traverseandcheck(intlist *p, char (*check)(intlist *, int), int a);

/* restituisce il primo elemento per cui check e' vera oppure NULL*/
intlist *getcheckelem(intlist *p, char(*check)(intlist *, int), int a);

/* restituisce vero se p->dato == elem */ 
char checkexist(intlist *p, int elem);

/* restituisce vero se l'elemento e' presente nella lista */
char existsinlist(intlist *p, int elem);

/* restituisce il primo elemento q per cui q->dato == elem */
intlist *geteleminlist(intlist *p, int elem);

/* End of file intdummylist.h */