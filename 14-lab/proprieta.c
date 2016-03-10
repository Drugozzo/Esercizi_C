#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lsada.h"

void gen(Graph g,int p);

int main(void){
	
	Graph g;
	int i,j,p;
	time_t t;

	srand((unsigned) time(&t));
	printf("%f\n",(double)rand()/(double)RAND_MAX );
	/*for(i=0;i<g->n;i++){
		for(j=0;j<g->n;j++){
			if(i!=j){

			}
		}
	}*/


	return 0;
}

void gen(Graph g,int p){
	
}