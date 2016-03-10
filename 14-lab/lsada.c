#include <stdio.h>
#include <stdlib.h>
#include "lsada.h"

Graph graph_new(int n,int e){
	Graph g;
	g = malloc(sizeof(Graph));

	if(!g)
		exit(-1);

	g->A=calloc(n,sizeof(struct listnode *));
	if(!g->A)
		exit(-1);

	g->n = n;
	g->m = e;

	return g;
}

void graph_destroy(Graph g){
	int i;
	listnode n;
	for(i=0;i<g->n;i++){
		for(n=g->A[i];n!=NULL;n=n->next){
			free(n);
		}
		free(g->A[i]);
	}
	free(g);
}

listnode graph_edgeinsert(listnode n, int v){
	listnode q = malloc(sizeof(listnode));
	q->v = v;
	q->next=n;
	return q;
}

Graph graph_read(void){
	int i,n,e,v1,v2;
	Graph g;

	printf("Inserisci il numero di nodi: ");
	scanf("%d",&n);
	printf("Inserisci il numero di archi: ");
	scanf("%d",&e);

	g=graph_new(n,e);

	for(i=0;i<g->m;i++){
		printf("Arco: %d\n",i );
		scanf("%d",&v1);
		scanf("%d",&v2);
		g->A[v1-1]=graph_edgeinsert(g->A[v1-1],v2);
		g->A[v2-1]=graph_edgeinsert(g->A[v2-1],v1);
	}
	return g;
}

void print_node(listnode n){
	if(n->next!=NULL)
		print_node(n->next);
	printf("%d ", n->v);
}

void graph_print(Graph g){
	int i;

	printf("Liste di adiacenza\n");
	for(i=0;i<g->n;i++){
		printf("%d) ",i+1);
		if(g->A[i])
			print_node(g->A[i]);
		printf("\n");
	}
}

void dfs1(Graph g, int i, int *aux){
	listnode n;
	aux[i]=1;
	for(n=g->A[i];n!=NULL;n=n->next){
		if(aux[n->v-1]==0){
			printf("%d ",n->v );
			dfs1(g,n->v-1,aux);
		}
	}
}

void dfs(Graph g){
	int i, *aux;
	aux=calloc(g->n,sizeof(int));
	for(i=0;i<g->n;i++){
		if(aux[i]==0){
			printf("%d ", i+1);
			dfs1(g,i,aux);
		}
	}
	printf("\n");
	free(aux);
}



