#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

	int i,j;
	for(i=1;i<argc;i++)
		printf("%s ",argv[i]);

	printf("\n");

	for(i=1;i<argc;i++){
		for(j=0;argv[i][j]!='\0';j++){
			if (argv[i][j]=='a' || argv[i][j]=='e' || argv[i][j]=='o' || argv[i][j]=='i' || argv[i][j]=='u'){
				printf("%cf%c",argv[i][j],argv[i][j]);
			}else
				printf("%c",argv[i][j]);
		}
		printf(" ");
	}

	printf("\n");

	return 0;
}
