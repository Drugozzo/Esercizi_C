#include <stdio.h>

#define N 20

int main(void){
	
	char c, s[N];
	int i=0,j,pal=1;

	while((c=getchar())!='.'){
		s[i]=c;
		i++;
	}
	


	for(j=0;j<i;j++){
		printf("%c\n",s[j] );
	}

	printf("\n");
	i--;
	printf("%d\n",i );
	for(j=0;i>j;j++,i--){
		//printf("i: %c, j: %c\n",s[i],s[j] );
		if(s[i]!=s[j]){
			pal=0;
			break;
		}
	}

	(pal)?(printf("palindroma\n")):(printf("non palindroma\n"));

	return 0;
}