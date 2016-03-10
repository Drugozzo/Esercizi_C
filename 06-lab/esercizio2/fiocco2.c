#include <stdio.h>
#include "libpsgraph.h"

void fiocco(int x,int i);

int main(void){
	
	int x, i;

	scanf("%d",&x);
	scanf("%d",&i);

	start("fiocco.ps");
	fiocco(x, i);
	turn(120);
	fiocco(x, i);
	turn(120);
	fiocco(x, i);
	end();

	return 0;
}

void fiocco(int x, int i){
	if (i==0)
		draw(x);
	else{
		x=x/3;
		fiocco(x,i-1);
		turn(-60);
		fiocco(x,i-1);
		turn(120);
		fiocco(x,i-1);
		turn(-60);
		fiocco(x,i-1);
	
		
	}

}