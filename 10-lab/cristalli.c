#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int latoCristallo( int t );
char **creaMatrice( int n );
void stampaMatrice( char **m, int n );
void crist( char **m, int r0, int c0, int l );

int main(void){

	int t,l;
	char **m;

	scanf("%d",&t);
	l=latoCristallo(t);
	
	m=creaMatrice(l);
	printf("%c\n",m[0][0]);
	printf("%d\n",l );
	crist(m,l/2,l/2,l);
	stampaMatrice(m,l);
	return 0;
}

int latoCristallo(int t){
	if(t==0)
		return 1;
	else
		return latoCristallo(t-1)*2+1;
}

char **creaMatrice(int n){
	char **m;
	int i,j;
	m=malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		m[i]=malloc(n*sizeof(char));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			m[i][j]='.';
	return m;
}

void stampaMatrice(char **m, int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%c ",m[i][j]);
		printf("\n");
	}
	printf("\n");


}

void crist( char **m, int r0, int c0, int l ){
	if(l==1)
		m[r0][c0]='*';
	else{
		m[r0][c0]='*';
		crist(m,r0-l/4,c0-l/4,l/2);
		crist(m,r0-l/2,c0+l/4,l/2);
		crist(m,r0+l/4,c0-l/4,l/2);
		crist(m,r0+l/4,c0+l/4,l/2);
	}
}
