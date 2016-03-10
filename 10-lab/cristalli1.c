#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int latoCristallo( int t );
char **creaMatrice( int n );
void stampaMatrice( char **m, int n );
void crist( char **m, int r0, int c0, int l );

int main(void){

	char **m;
	int t,l;
	scanf("%d",&t);
	l=latoCristallo(t);
	printf("%d\n",l );
	m=creaMatrice(l);
	stampaMatrice(m,l);
	//crist(m,l,l,l);
	stampaMatrice(m,l);
	return 0;
}

int latoCristallo( int t ){
	if(t==0)
		return 1;
	else{
		if(t==1)
			return 3;
		else
			return latoCristallo(t-1)*2+1;
	}
}

char **creaMatrice( int n ){
	char **m;
	int i,j;
	m=malloc(n*sizeof(char));
	for(i=0;i<n;i++){
		m[i]=malloc(n*sizeof(char));
	}
	printf("ciao\n");
	for(i=0;i<n;i++){
		strcpy(m[i],".");
		printf("QUASI\n");

		/*for(j=0;j<n;j++){
			printf("NO\n");
			m[i][j]='.';
		}*/
	}
	printf("QUASI\n");

	return m;
}

void stampaMatrice( char **m, int n ){
	int i;
	for(i=0;i<n;i++)
		printf("%s\n", m[i]);
}

void crist( char **m, int r0, int c0, int l ){
	if(l==1)
		m[r0][c0]='*';
	else
		crist(m,0,0,l-1);
		crist(m,0,c0/l,l-1);
		crist(m,r0,0,l-1);
		crist(m,r0/l,c0/l,l-1);
}


