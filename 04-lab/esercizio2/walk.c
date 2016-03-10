#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

enum Move{SU,GIU,DESTRA,SINISTRA};

int main(void){
	
	char m[N][N],c=65;
	int i,j,n,a[4],BS=0,BG=0,BDx=0,BSx=0;

	//enum Move n;

	srand((time(NULL)));

	for(i=0;i<4;i++)
		a[i]=1;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			m[i][j]='.';
			//printf("%2c ",m[i][j]);
		}
		//printf("\n");
	}
	i=0;
	j=0;

	while(c<=90){
	//for(c=65;c<=90;c++){
		m[i][j]=c;
		n=rand()%4;
		//printf("%d\n",n);
		//printf("%c\n",c );
		//r++;
		switch(n){

			case 0://SU:
			if((i-1)>=0 && m[i-1][j]=='.'){
				i--;
				c++;
				BS=0;
			}else{
				BS=1;
			}			
			break;

			case 1://GIU:
			if((i+1)<N && m[i+1][j]=='.'){
				i++;
				c++;
				BG=0;
			}else{
				BG=1;
			}			
			break;

			case 2://DESTRA:
			if((j+1)<N && m[i][j+1]=='.'){
				j++;
				c++;
				BDx=0;
			}else{				
				BDx=1;
			}			
			break;

			case 3://SINISTRA:
			if((j-1)>=0 && m[i][j-1]=='.'){
				j--;
				c++;
				BSx=0;
			}else{				
				BSx=1;
			}			
			break;
		}

		if(BS==1 && BG==1 && BDx==1 && BSx==1){
			printf("bloccato\n");
			break;
		}

	}

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%2c ",m[i][j]);
		}
		printf("\n");
	}




	return 0;
}