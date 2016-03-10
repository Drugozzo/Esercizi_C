#include <stdio.h>

int main(int argc, char **argv){

	char *p;

	for(p=argv[1];*p!='\0';p++){
		printf("%c",*p);
		if(*(p+1)<*p && *(p+1)!='\0')
			printf("-");
	}
	printf("\n");

	return 0;
}

