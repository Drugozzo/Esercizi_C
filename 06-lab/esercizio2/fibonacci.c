#include <stdio.h>

int cont=0;

int fibo(int n);

int main(void){

	int n;
	scanf("%d",&n);
	printf("%d\n",fibo(n));
	printf("%d\n",cont );
	return 0;
}

int fibo(int n){
	
	fcont++;

	if (n==2 || n==1){
		return 1;
	}else{
		return fibo(n-1)+fibo(n-2);
	}
}


