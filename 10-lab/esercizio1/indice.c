#include <stdio.h>
#include <string.h>

int smallest_word_index( char *s[], int n );

int main(void){

	char *dict[] = { "ciao", "mondo", "come", "funziona", "bene", "questo", "programma" };
	int pos,n=7,i;

	pos = smallest_word_index(dict,n);

	printf("%d\n", pos);



	return 0;
}

 int smallest_word_index( char *s[], int n ){
 	int i,j=0;
 	for(i=1;i<n;i++){
 		if(strcmp(s[i],s[j])<0){
 			j=i;
 		}
 	}
 	return j;
}
