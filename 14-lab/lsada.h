typedef struct graph *Graph; 
typedef struct listnode *listnode ;

struct listnode {
	struct listnode *next; 
	int v;
};

struct graph {
	int n, m;
	struct listnode **A;
};


Graph graph_new( int n, int e); /* crea un grafo con n nodi */

void graph_destroy( Graph g ); /* distrugge il grafo g */

listnode graph_edgeinsert( listnode n, int v); /* inserisce l’arco (v,w) nel grafo g */

Graph graph_read( void ); /* legge da standard input un grafo (specificare il formato!!) */

void print_node(listnode n);

void graph_print( Graph g ); /* stampa su standard output un grafo (specificare il formato!!) */

void dfs1(Graph g, int i, int *aux);

void dfs(Graph g);
