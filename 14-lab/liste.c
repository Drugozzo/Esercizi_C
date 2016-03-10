#include <stdio.h>
#include <stdlib.h>
#include "lsada.h"

int main(void){

	Graph g;
	g=graph_read();
	graph_print(g);

	printf("Vista in profondità\n");
	dfs(g);

	return 0;
}

