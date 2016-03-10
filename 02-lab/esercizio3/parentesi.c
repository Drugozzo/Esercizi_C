#include <stdio.h>

int main(void){
	
	int aperte=0, chiuse=0,ris=1;
	char c;

	while((c=getchar())!='.'){
		switch(c){

			case '(':
			aperte++;
			break;

			case ')':
			if(aperte<chiuse)
				ris=0;
			else
				chiuse++;
		}
	}

	if(chiuse!=aperte)
		ris=0;

	(ris)?(printf("parentesizzata\n")):(printf("non parentesizzata\n"));

	return 0;
}