#include <stdio.h>

void hanoi(int n, int from, int to, int temp);

int main(void){

	int n, from=0, to=2, temp=1;
	scanf("%d",&n);
	hanoi(n,from, to, temp);
	return 0;
}

void hanoi(int n, int from, int to, int temp){
	if(n==1)
		printf("%d->%d\n",from,to);
	else{
		n--;
		hanoi(n,from,temp,to);
		printf("%d->%d\n",from,to);
		hanoi(n,temp,to,from);
	}
}
