#include <stdio.h>
#include <stdlib.h>
#include "mtrada.h"

char *read_line( void ){
	int size=2,n=0;
	char *p,*temp,c;

	p=malloc(size*sizeof(int));

	while(1){
		c=getchar();
		if(c!='\n'){
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

Graph graph_new(int n){
	int i; Graph g;
  	
  	/* alloca lo spazio per una struct graph */
  	g = malloc(sizeof(struct graph) );
  	if(!g)
  		exit(-1);

	/* alloca lo spazio per un array di n puntatori a int */
	g -> A = calloc( n, sizeof(int *) );
	for ( i = 0; i < n; i++ ){
		/* alloca lo spazio per l’array A[i] di n interi, inizialmente nulli */ 
		g -> A[i] = calloc( n, sizeof( int ) );
	}
	g -> n = n;
	g -> m = 0;
	return g;
}

void graph_destroy(Graph g){
	int i;
	for(i=0;i<g->n;i++)
		free(g->A[i]);
	free(g->A);
	free(g);
}

void graph_edgeinsert(Graph g, int v, int w){
	g->A[v][w]=1;
	g->A[w][v]=1;
	g->m++;
}

Graph graph_read(void){
	Graph g;
	int n,i=0,v,w;
	char *s;

	printf("Inserire il numero di nodi: ");
	scanf("%d",&n);
	getchar();
	g=graph_new(n);
	printf("Scrivere una sequenza contenente i lati del grafo terminata da un a capo\nEsempio: (v0,v1)(v2,v3). con {v0...v3}€V e (v0,v1),(v2,v3)€E\n");
	s=read_line();
	while(s[i]!='\0'){
		if(s[i]=='('){
			i++;
			v=s[i]-'0';
			i+=2;
			w=s[i]-'0';
			graph_edgeinsert(g,v,w);
		}
		i++;
	}
	return g;
}

void graph_print(Graph g){
	int i,j;
	printf("Matrice di adiacenza\n");

	for(i=0;i<g->n;i++){
		for(j=0;j<g->n;j++){
			printf("%d ", g->A[i][j]);
		}
		printf("\n");
	}

	printf("Il grafico ha %d lati\n",g->m );
}
