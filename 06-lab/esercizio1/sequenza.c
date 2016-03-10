#include <stdio.h>

#define N 500

int succ(int n);

int main(void){

	int n,cont=0;

	scanf("%d",&n);

	while(n!=1){
		printf("%d ",n);
		n=succ(n);
		cont++;
	}

	printf("\n%d\n",cont );
	return 0;
}

int succ(int n){
	
	if(n%2==0)
		return n/2;
	else
		return n*3+1;
}
