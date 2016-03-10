#include <stdio.h>
#include <ctype.h>

int main(void){

	char ch;

	scanf("%c",&ch);
	ch = tolower(ch);

	if(ch==97 || ch==101 || ch==105 || ch==111 || ch==117)
		printf("vocale alfabeto italiano\n");
	else{
		if((ch>97 && ch<118 && ch!=106) || ch==122)
			printf("consonante alfabeto italiano\n");
		else
			printf("carattere non appartenente all'alfabeto italiano\n");
	}

	return 0;
}