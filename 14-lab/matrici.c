#include <stdio.h>
#include <stdlib.h>
#include "mtrada.h"

int main(void){

	Graph g;
	g=graph_read();
	graph_print(g);

	return 0;
}
