
typedef struct graph *Graph; 

struct graph {
	int n, m; /* n = num vertici, m = num lati */ 
	int **A; /* matrice di adiacenza */
};

char *read_line();

Graph graph_new( int n ); /* crea un grafo con n nodi */

void graph_destroy( Graph g ); /* distrugge il grafo g */

void graph_edgeinsert( Graph g, int v, int w ); /* inserisce l’arco (v,w) nel grafo g */

Graph graph_read( void ); /* legge da standard input un grafo (specificare il formato!!) */

void graph_print( Graph g ); /* stampa su standard output un grafo (specificare il formato!!) */