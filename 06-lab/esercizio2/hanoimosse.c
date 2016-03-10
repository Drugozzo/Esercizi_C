#include <stdio.h>
#include <time.h>

int m=0;

void hanoi(int n, int from, int to, int temp);
void mosse();

int main(void){

	int n, from=0, to=2, temp=1;
	time_t s, s2;
	s=time(NULL);
	scanf("%d",&n);
	hanoi(n,from, to, temp);
	printf("\n%d\n",m);
	s2=time(NULL);
	printf("%ld %ld\n",s,s2);
	printf("%ld\n",(s2-s));
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
	m++;
}

void mosse(){
	m++;
}
