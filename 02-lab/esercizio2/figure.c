#include <stdio.h>

int mod(int n){return n>0?n:-n;}

int main(void){
	
	int n,i,j,k;
	char c;
	
	printf("righe alternate: 1\ncifre alternate: 2\ntriangolo: 3\nrombo (solo n dispari): 4\n");
	scanf("%d",&k);
	scanf("%d",&n);
	switch(k){

		case 1:
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i%2!=0)
					c='o';
				else
					c='+';
				printf("%c ",c);
			}
			printf("\n");
		}
		break;

		case 2:
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(c=='o')
					c='+';
				else
					c='o';
				printf("%c ",c);
			}
			if(n%2==0){
				if(c=='+')
					c='o';
				else
					c='+';
			}
			printf("\n");
		}
		break;

		case 3:
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j==i)
					printf("| ");
				else{
					if(j>i)
						printf("+ ");
					else 
						printf("o ");
				}
			}
			printf("\n");
		}
		break;
	
		case 4:
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if ( j < mod((n-(2*i+1))/2) || j >= n-mod((n-(2*i+1))/2) ) printf("| "); else printf("o "); 
			}
			printf("\n");
		}


		break;

	}
	return 0;
}