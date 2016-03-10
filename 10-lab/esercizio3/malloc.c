#include <stdio.h>
#include <stdlib.h>

void my_malloc(int *p);
void my_realloc(int *p);

int main(void){

	int *p;
	my_malloc(p);
	my_realloc(p);
	return 0;
}

void my_malloc(int *p){
	p = malloc(1000);
	if(!p)
		exit(EXIT_FAILURE);
	else
		printf("%p\n",p);
}

void my_realloc(int *p){

	realloc(p,10000);
	if(!p)
		exit(EXIT_FAILURE);
	else
		printf("%p\n",p );


}

