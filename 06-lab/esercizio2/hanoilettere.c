#include <stdio.h>

#define N 26

void hanoi(int n, char from[], char to[], char temp[]);

int main(void){

	int n,i;
	char from[N], to[N], temp[N];
	char c;
	scanf("%d",&n);
	for(i=0,c='A';i<n;i++,c++)		/*1)incrementa 2)condizione*/
		from[i]=c;
	from[i]='.';
	to[0]='.';
	temp[0]='.';
	hanoi(n,from, to, temp);
	return 0;
}

void hanoi(int n, char from[], char to[], char temp[]){
	int j=0,k=0;
	char t,r;
	if(n==1){
		j=0;
		while(j<N && from[j]!='.'){
			printf("%c",from[j]);
			j++;
		}
		j=0;
		printf(", ");
		while(j<N && temp[j]!='.'){
			printf("%c",temp[j]);
			j++;
		}
		j=0;
		printf(", ");
		while(j<N && to[j]!='.'){
			printf("%c",to[j]);
			j++;
		}
		printf("\n");

	}else{
		n--;
		
		hanoi(n,from,temp,to);


		while(from[j]!='.'){
			j++;
		}
		
		for(k=0,r=from[j-1];temp[k+1]!='.';k++){
			t=temp[k];
			temp[k]=r;
			r=t;
		}
		from[j-1]='.';
			
		j=0;
		while(j<N && from[j]!='.'){
			printf("%c",from[j]);
			j++;
		}
		j=0;
		printf(", ");
		while(j<N && temp[j]!='.'){
			printf("%c",temp[j]);
			j++;
		}
		j=0;
		printf(", ");
		while(j<N && to[j]!='.'){
			printf("%c",to[j]);
			j++;
		}
		printf("\n");
		j=0;

		while(temp[j]!='.'){
			j++;
		}
		for(k=0,r=temp[j-1];to[k+1]!='.';k++){
			t=to[k];
			to[k]=r;
			r=t;
		}
		from[j-1]='.';

		hanoi(n,temp,to,from);

	}

}
